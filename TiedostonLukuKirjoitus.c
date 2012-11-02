/* 
 * File:   TiedostonLukuKirjoitus.c
 * Author: Vili Lehtinen & Anis Moubarik
 * Tiedosto sisältää sukupuun tallentamisen tiedostoon, lukemisen tiedostosta ja sinne kirjoittamisen. Sekä suhteiden tallennuksen ja lukemisen tekstitiedostosta.Käyttää hyväksi HenkiloLista.h ja  henkilo.h.
 * Created on 28 October 2011, 17:42
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "henkilo.h"
#include "HenkiloLista.h"


//const char *filename = "sukupuu.txt";

int getFileSize(char *filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Piäleen män!\n");
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fclose(fp);
    return sz;
}

void lueSukupuuTiedostosta(char *filename) {
    int filesize = getFileSize(filename);
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Piäleen män!\n");
        exit(1);
    }
    char c;
    char file[filesize+1];
    file[filesize] = '\0';
    int j = 0;
    while ((c = getc(fptr)) != EOF) {
        file[j] = c;
        j++;
    }

    char enimiA[50] = {"\000"};
    char snimiA[50] = {"\000"};
    char enimiB[50] = {"\000"};
    char snimiB[50] = {"\000"};
    char syntymaaika[12] = {"\000"};
    char kuolinaika[12] = {"\000"};
    int lastenlkm = 0;

    char *line = strtok(file, "\n");
    while (line != NULL) {
        if (strlen(line) > 1) {
            if (sscanf(line, "%s %s %s %s %d", enimiA, snimiA, syntymaaika, kuolinaika, &lastenlkm) == 5) {
                // yo. tietojen perusteella voidaan lisätä uusi struct henkilo
                // syytä on kuitenkin ottaa huomioon miten käsitellään puuttuvia tietoja
                // puuttuvat tiedot on merkattava tiedostoon jotenkin, esimerkiksi viivalla
                // tiedostosta luettu viiva voidaan korvata esim. tyhjällä stringillä "" henkilöä lisättäessä
                // HOX! Von Hertzen on tiedostossa Von_Hertzen. structia luodessa _ pitää korvata välilyönnillä
                henkilo *hlo = (henkilo *) calloc(1, sizeof (henkilo));
                strcpy(hlo->enimi, enimiA);
                strcpy(hlo->snimi, snimiA);
                strcpy(hlo->syntymaaika, syntymaaika);
                strcpy(hlo->kuolinaika, kuolinaika);
                hlo->lastenlkm = lastenlkm;
                hlo->suhde = NULL;

                lisaa_henkilo(hlo);
                free(hlo);
            } else if (sscanf(line, "%s %s isa %s %s\n", enimiA, snimiA, enimiB, snimiB) == 4) {
                henkilo *poika = hae(enimiA, snimiA);
                henkilo *faija = hae(enimiB, snimiB);

                poika->isa = faija;
                faija->lapset[faija->lastenlkm] = poika;
                faija->lastenlkm++;

            } else if (sscanf(line, "%s %s aiti %s %s\n", enimiA, snimiA, enimiB, snimiB) == 4) {
                henkilo *lapsi = hae(enimiA, snimiA);
                henkilo *mutsi = hae(enimiB, snimiB);

                lapsi->aiti = mutsi;
                mutsi->lapset[mutsi->lastenlkm] = lapsi;
                mutsi->lastenlkm++;

            } else if (sscanf(line, "%s %s suhde %s %s\n", enimiA, snimiA, enimiB, snimiB) == 4) {
                henkilo *pari = hae(enimiA, snimiA);
                henkilo *suh = hae(enimiB, snimiB);
                
                pari->suhde = suh;
                suh->suhde = pari;
            }
            // yo. tietojen perusteella voidaan lisätä isä, äiti, suhde sekä lapsi henkilölle
            // lapsen ja vanhempien lisääminen kannattaa(?) tehdä samassa funktiossa
            // henkilöt yksilöidään nimen perusteella, olettaen ettei sukupuussa ole samannimisiä henkilöitä
            // suhteen laatua ei huomioida. suhde on suhde, oli se sitten avio- tai avoliitto tai vaikka syrjähyppy

        }
        line = strtok(NULL, "\n");
    }
    fclose(fptr);
}

void kirjoitaAitiSukupuuTiedostoon(henkilo *h, char *filename) {
    if (h->aiti == NULL) {
        return;
    }
    char * henkilonEnimi = h->enimi;
    char * henkilonSnimi = h->snimi;
    char * aidinEnimi = h->aiti->enimi;
    char * aidinSnimi = h->aiti->snimi;


    FILE* fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Piäleen mänj!\n");
        exit(1);
    }
    fprintf(fptr, "%s %s aiti %s %s\n", henkilonEnimi, henkilonSnimi, aidinEnimi, aidinSnimi);
    fclose(fptr);

}

void kirjoitaIsaSukupuuTiedostoon(henkilo *h, char *filename) {
    if (h->isa == NULL) {
        return;
    }
    char * henkilonEnimi = h->enimi;
    char * henkilonSnimi = h->snimi;
    char * isanEnimi = h->isa->enimi;
    char * isanSnimi = h->isa->snimi;

    FILE* fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Piäleen mänj!\n");
        exit(1);
    }
    fprintf(fptr, "%s %s isa %s %s\n", henkilonEnimi, henkilonSnimi, isanEnimi, isanSnimi);
    fclose(fptr);

}

void kirjoitaSuhdeSukupuuTiedostoon(henkilo *h, char *filename) {
    if (h->suhde == NULL) {
        return;
    }
    char * enimiA = h->enimi;
    char * snimiA = h->snimi;
    char * enimiB = h->suhde->enimi;
    char * snimiB = h->suhde->snimi;


    FILE* fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Piäleen mänj!\n");
        exit(1);
    }
    fprintf(fptr, "%s %s suhde %s %s\n", enimiA, snimiA, enimiB, snimiB);
    fclose(fptr);


}

void kirjoitaHenkiloSukupuuTiedostoon(henkilo *h, char *filename) {

    char * enimi = h->enimi;
    char * snimi = h->snimi;
    char * saika = h->syntymaaika;
    char * kaika = h->kuolinaika;
    int lastenlkm = 0;


/*    char rivi[150] = {'\0'};
    strcat(rivi, enimi);
    strcat(rivi, " ");
    strcat(rivi, snimi);
    strcat(rivi, " ");
    strcat(rivi, saika);
    strcat(rivi, " ");
    strcat(rivi, kaika);
    strcat(rivi, " ");

    sprintf(rivi, "%s%d", rivi, lastenlkm);

    strcat(rivi, "\n");
*/

    FILE* fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Piäleen män!\n");
        exit(1);
    }

    //fputs(rivi, fptr);
    fprintf(fptr, "%s %s %s %s %d\n", enimi, snimi, saika, kaika, lastenlkm);


    fclose(fptr);
}

void tallennaSukupuuTiedostoon() {
    henkilo* h = getHead();
    FILE* fptr = fopen("sukupuu.txt", "w");
    if (fptr == NULL) {
        printf("Piäleen män!\n");
        exit(1);
    }

    fclose(fptr);
    while (h != NULL) {
        kirjoitaHenkiloSukupuuTiedostoon(h, "sukupuu.txt");
        h = h->next;
    }

    h = getHead();
    while (h != NULL) {
        kirjoitaSuhdeSukupuuTiedostoon(h, "sukupuu.txt");
        kirjoitaIsaSukupuuTiedostoon(h, "sukupuu.txt");
        kirjoitaAitiSukupuuTiedostoon(h, "sukupuu.txt");
        h = h->next;
    }
}
