/* 
 * File:   henkilo.c
 * Author: Anis Moubarik & Anna Hietanen
 * Tiedosto sisältää henkilön lisäämistä sekä henkilön tietojen ja suhteiden muokkaamista koskevat funktiot. Se käyttää hyväksi henkilo.h ja HenkiloLista.h tiedostoja.
 * Created on 17. lokakuuta 2011, 12:08
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "henkilo.h"
#include "HenkiloLista.h"
#include <string.h>
#include <assert.h>
#include <stdbool.h>



void lisaa_henkilo(henkilo *hlo)
{
        lisaa_listaan(hlo);
}

void muokkaaHenkilonTietoja(henkilo* hlo)
{
    int valinta;
    char enimi[50], snimi[50], syntymaika[12], kuolinaika[12];
    system("clear");
    printf("1. Muokkaa nimeä\n2. Muokkaa syntymäaikaa\n3. Muokkaa kuolinaikaa\n4. Poistu\n");
    scanf("%1d", &valinta);
    
    switch(valinta)
    {
        case 1:
            printf("Anna uusi etu- ja sukunimi: ");
            scanf("%s %s", enimi, snimi);
            strcpy(hlo->enimi, enimi); strcpy(hlo->snimi, snimi);
            system("clear");
            printf("Nimi muokattu.\n");
            return;
            
        case 2:
            printf("Anna uusi syntymäaika: ");
            scanf("%12s", syntymaika);
            strcpy(hlo->syntymaaika, syntymaika);
            system("clear");
            printf("Syntymäaika muokattu.\n");
            return;
            
        case 3:
            printf("Anna uusi kuolinaika: ");
            scanf("%12s", kuolinaika);
            strcpy(hlo->kuolinaika, kuolinaika);
            system("clear");
            printf("Kuolinaika muokattu.\n");
            return;
           
        case 4:
            return;
          
            
       default:
           printf("Väärä valinta");
           return;
    }
}

int henkilonMuokkaus()
{
    char enimi[50], snimi[50];
    henkilo* h;
    printf("Anna henkilön etu- ja sukunimi: ");
    scanf("%50s %50s", enimi, snimi);
    h = hae(enimi, snimi);
    if(h != NULL)
    {
        system("clear");
        printf("Henkilö löytyi\n");
        muokkaaHenkilonTietoja(h);
        return 1;
    }
    else
    {
        return 0;
    }
}

henkilo* otaJaLisaaHenkilonTiedot()
{
    henkilo *hlo = (henkilo *)calloc(1, sizeof(henkilo));
    
    //Annetaan nimi, syntymäaika ja kuolinaika, ja syötetään se hlo:lle
    printf("Anna nimi: " );
    scanf("%50s %50s", hlo->enimi, hlo->snimi);
    printf("Syntymäaika: ");
    scanf("%12s", hlo->syntymaaika);
    printf("Kuolinaika (kirjoita null, jos et ole kuollut): ");
    scanf("%12s", hlo->kuolinaika);
    
    lisaa_henkilo(hlo);
    free(hlo);
    return hlo;
    
}



void muutaSuhde(henkilo* hlo, henkilo* partneri)
{
       char valinta = 0;
       printf("Haluatko muuttaa suhdetta %s %s -> %s %s? (y/n): ", partneri->suhde->enimi, partneri->suhde->snimi, partneri->enimi, partneri->snimi);
            scanf("%s", &valinta);
            if(valinta == 'y')
            {
                partneri->suhde->suhde = NULL;
                partneri->suhde = hlo;
                hlo->suhde = partneri;
            }
}

bool onkoPariSuhdetta(henkilo *eka, henkilo *toka)
{
    if(eka->suhde != NULL || toka->suhde != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void lisaaSuhde()
{
    char etuNimi[50], sukuNimi[50];
    int valinta;
    printf("Anna henkilön etu- ja sukunimi: ");
    scanf("%50s %50s", etuNimi, sukuNimi);
    henkilo *hlo = hae(etuNimi, sukuNimi), *isa, *aiti, *suhde;
    if(hlo == NULL)
    {
        printf("Henkilöä ei löytynyt\n");
        return;
    }
    
    printf("\n1. Lisää isä\n2. Lisää äiti\n3. Lisää rekisteröity suhde\n4. Lisää lapsi\n");
    scanf("%1d", &valinta);
    
    switch(valinta)
    {
        case 1:
            system("clear");
            printf("Anna isän etu- ja sukunimi: ");
            scanf("%50s %50s", etuNimi, sukuNimi);
            isa = hae(etuNimi, sukuNimi);
            if(isa == NULL)
            {
                printf("Isää ei löytynyt\n\n");
                break;
            }
            lisaaIsa(hlo, isa);
            break;
            
        case 2:
            system("clear");
            printf("Anna äidin etu- ja sukunimi: ");
            scanf("%50s %50s", etuNimi, sukuNimi);
            aiti = hae(etuNimi, sukuNimi);
            if(aiti == NULL)
            {
                printf("Äitiä ei löytynyt\n\n");
                break;
            }
            lisaaAiti(hlo, aiti);
            break;
            
        case 3:
            printf("Anna partnerin etu- ja sukunimi: ");
            scanf("%50s %50s", etuNimi, sukuNimi);
            suhde = hae(etuNimi, sukuNimi);
            if(onkoPariSuhdetta(hlo, suhde) == true)
            {
                muutaSuhde(hlo, suhde);
                return;
            }
            else
            {
                lisaaRekisteroitySuhde(hlo, suhde);
            }
    }
    
}

void lisaaIsa(henkilo* lapsi, henkilo* isa)
{
    lapsi->isa = isa;
    isa->lapset[isa->lastenlkm] = lapsi;
    assert(strcmp(isa->lapset[isa->lastenlkm]->enimi, lapsi->enimi) == 0);
    assert(strcmp(lapsi->isa->enimi, isa->enimi) == 0);
    isa->lastenlkm++;
    printf("Suhteen lisääminen onnistui\n");
}

void lisaaAiti(henkilo* lapsi, henkilo* aiti)
{
    lapsi->aiti = aiti;
    aiti->lapset[aiti->lastenlkm] = lapsi;
    assert(strcmp(aiti->lapset[aiti->lastenlkm]->enimi, lapsi->enimi) == 0);
    assert(strcmp(lapsi->aiti->enimi, aiti->enimi) == 0);
    aiti->lastenlkm++;
    printf("Suhteen lisääminen onnistui\n");
}

void lisaaRekisteroitySuhde(henkilo* hlo, henkilo *suhde)
{
    hlo->suhde = suhde;
    suhde->suhde = hlo;
    assert(strcmp(suhde->suhde->enimi, hlo->enimi) == 0);
    assert(strcmp(hlo->suhde->enimi, suhde->enimi) == 0);
    printf("Suhteen lisääminen onnistui\n");
}
