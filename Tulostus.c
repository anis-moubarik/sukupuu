/* 
 * File:   Tulostus.c
 * Author: Anis Moubarik & Anna Hietanen
 * Tiedosto sisältää ohjelman tulostamista koskevat funktiot.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "henkilo.h"
#include "Tulostus.h"
#include "HenkiloLista.h"

void tulostus()
{
    int valinta = 0;
    char etuNimi[50], sukuNimi[50];
    henkilo *hlo;
    system("clear");
    printf("\n1. Tulosta henkilön jälkeläiset\n2. Tulosta henkilön esivanhemmat\n3. Tulosta henkilön suhde\n4. Tulosta koko lista\n5. Poistu\n");
    scanf("%1d", &valinta);
    
    switch(valinta)
    {
        case 1:
            printf("Anna henkilön etu- ja sukunimi: ");
            scanf("%s %s", etuNimi, sukuNimi);
            hlo = hae(etuNimi, sukuNimi);
            if(hlo == NULL)
            {
                printf("Henkilöä ei ole olemassa!\n");
                return;
            }else{
                tulostaLapset(hlo);
            }
            return;
            
        case 2:
            printf("Anna henkilön etu- ja sukunimi: ");
            scanf("%s %s", etuNimi, sukuNimi);
            hlo = hae(etuNimi, sukuNimi);
            if(hlo == NULL)
            {
                printf("Henkilöä ei ole olemassa!\n");
                return;
            }else{
                tulostaVanhemmat(hlo);
            }
            return;
            
        case 3:
            printf("Anna henkilön etu- ja sukunimi: ");
            scanf("%s %s", etuNimi, sukuNimi);
            hlo = hae(etuNimi, sukuNimi);
            if(hlo == NULL)
            {
                printf("Henkilöä ei ole olemassa!\n");
                return;
            }else{
                tulostaSuhde(hlo);
            }
            return;
            
        case 4:
            tulostaLista();
            return;
            
        case 5:
            return;
    }
    return;
}

void tulostaLapset(henkilo *hlo)
{
    if(hlo->lapset[0] == NULL)
    {
        return;
    }
    
    for (int i = 0; i < hlo->lastenlkm; i++) {
        printf("Vanhempi: %s %s, Lapsi: %s %s\n\n",hlo->enimi, hlo->snimi, hlo->lapset[i]->enimi, hlo->lapset[i]->snimi);
        tulostaLapset(hlo->lapset[i]);
    }
}

void tulostaSuhde(henkilo *hlo)
{
    printf("%s %s", hlo->suhde->enimi, hlo->suhde->snimi);
    return;
}

void tulostaVanhemmat(henkilo *hlo)
{
    if(hlo->isa == NULL || hlo->aiti == NULL)
    {
        return;
    }
    else if(hlo->isa == NULL)
    {
        printf("%s : Äiti: %s %s\n", hlo->enimi, hlo->aiti->enimi, hlo->aiti->snimi);
        tulostaVanhemmat(hlo->aiti);
    }else if(hlo->aiti == NULL)
    {
        printf("%s : Isä: %s %s\n", hlo->enimi, hlo->isa->enimi, hlo->isa->snimi);
        tulostaVanhemmat(hlo->isa);
    }
    else
    {
        printf("%s : Isä: %s %s\n", hlo->enimi, hlo->isa->enimi, hlo->isa->snimi);
        printf("%s : Äiti: %s %s\n\n", hlo->enimi, hlo->aiti->enimi, hlo->aiti->snimi);
        tulostaVanhemmat(hlo->aiti);
        tulostaVanhemmat(hlo->isa);
    }
    
}
