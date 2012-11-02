/*
 * File:   henkiloTesti.c
 * Author: Anis Moubarik
 * Sisältää testit joilla tarkistetaan tulostuvatko henkilön suhteet oikein.
 * Created on Nov 5, 2011, 3:30:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "../henkilo.h"
#include "../HenkiloLista.h"
#include "../TiedostonLukuKirjoitus.h"

/* Testaa toimiiko suhteen lisäys */
void suhdeTesti();
/* Testaa isän lisäystä lapselle */
void isaLapsiTesti();
/* Testaa äidin lisäystä lapselle */
void aitiLapsiTesti();
/* Testaa kaikkien äidin lasten tulostusta */
void kaikkiAidinLapsetTesti();
/* Testaa kaikkien isän lasten tulostusta */
void kaikkiIsanLapsetTesti();

void suhdeTesti()
{
    henkiloidenAlustus();
    printf("henkiloTesti suhdeTesti\n");
/*
    char enimi[50], snimi[50];
    strcpy(enimi, "Tove");
    strcpy(snimi, "Jansson");
*/
    henkilo *marie = hae("Marie", "Curie");
    henkilo *tove = hae("Tove", "Jansson");
    if(assertMyStringEquals(tove->suhde->enimi, marie->enimi) && assertMyStringEquals(tove->suhde->snimi, marie->snimi)
            && assertMyStringEquals(marie->suhde->enimi, tove->enimi) && assertMyStringEquals(marie->suhde->snimi, tove->snimi))
    {
        printf("suhdeTesti passed\n");
    }
    else
    {
        printf("%%TEST_FAILED%% time=0 testname=suhdeTesti (henkiloTesti) error=Epäselvä suhde\n");
    }
    destroyList();
}

void isaLapsiTesti()
{
    //Tässä testissä oletetaan, että isällä on vain yksi lapsi
    henkiloidenAlustus();
    printf("henkiloTesti isaTesti\n");
    henkilo *alan = hae("Alan", "Turing");
    henkilo *bill = hae("Bill", "Gates");
    
    char *alanOsoite = (char *)alan;
    char *billIsaOsoite = (char *)bill->isa;
    char *billOsoite = (char *)bill;
    char *alanLapsiOsoite = (char *)alan->lapset[0];
    
    if(!assertMyPointerEquals(alanOsoite, billIsaOsoite) || !assertMyPointerEquals(alanLapsiOsoite, billOsoite))
    {
        printf("%%TEST_FAILED%% time=0 testname=isaLapsiTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    else
    {
        printf("isaLapsiTesti passed\n");
    }
    
    destroyList();
    
}

void aitiLapsiTesti()
{
    //Tässä testissä oletetaan, että isällä on vain yksi lapsi
    henkiloidenAlustus();
    printf("henkiloTesti isaTesti\n");
    henkilo *barbara = hae("Barbara", "Streisand");
    henkilo *bill = hae("Bill", "Gates");
    
    char *barbaraOsoite = (char *)barbara;
    char *billAitiOsoite = (char *)bill->aiti;
    char *billOsoite = (char *)bill;
    char *barbaraLapsiOsoite = (char *)barbara->lapset[0];
    
    if(!assertMyPointerEquals(barbaraOsoite, billAitiOsoite) || !assertMyPointerEquals(barbaraLapsiOsoite, billOsoite))
    {
        printf("%%TEST_FAILED%% time=0 testname=aitiLapsiTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    else
    {
        printf("aitiLapsiTesti passed\n");
    }
    
    destroyList();
    
}

void kaikkiAidinLapsetTesti()
{
    //Testataan jokainen lapsi
    henkiloidenAlustus();
    printf("henkiloTesti kaikkiAidinLapsetTesti\n");
    henkilo *barbara = hae("Barbara", "Streisand");
    henkilo *bill = hae("Bill", "Gates");
    henkilo *linus = hae("Linus", "Torvalds");
    henkilo *jesus = hae("Jesus", "Kristus");
    
    if(!assertMyPointerEquals((char *)barbara->lapset[0], (char *)bill) || !assertMyPointerEquals((char *)bill->aiti, (char *)barbara))
    {
        printf("%%TEST_FAILED%% time=0 testname=kaikkiAidinLapsetTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    if(!assertMyPointerEquals((char *)barbara->lapset[1], (char *)bill) || !assertMyPointerEquals((char *)linus->aiti, (char *)barbara))
    {
        printf("%%TEST_FAILED%% time=0 testname=kaikkiAidinLapsetTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    if(!assertMyPointerEquals((char *)barbara->lapset[1], (char *)bill) || !assertMyPointerEquals((char *)jesus->aiti, (char *)barbara))
    {
        printf("%%TEST_FAILED%% time=0 testname=kaikkiAidinLapsetTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    else
    {
        printf("kaikkiAidinLapsetTesti test passed\n");
    }
    
    destroyList();
}

void kaikkiIsanLapsetTesti()
{
    //Testataan jokainen lapsi
    henkiloidenAlustus();
    printf("henkiloTesti kaikkiIsanLapsetTesti\n");
    henkilo *alan = hae("Alan", "Turing");
    henkilo *bill = hae("Bill", "Gates");
    henkilo *tove = hae("Tove", "Jansson");
    henkilo *steve = hae("Steve", "Jobs");
    
    if(!assertMyPointerEquals((char *)alan->lapset[0], (char *)bill) || !assertMyPointerEquals((char *)bill->isa, (char *)alan))
    {
        printf("%%TEST_FAILED%% time=0 testname=kaikkiIsanLapsetTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    if(!assertMyPointerEquals((char *)alan->lapset[1], (char *)bill) || !assertMyPointerEquals((char *)tove->isa, (char *)alan))
    {
        printf("%%TEST_FAILED%% time=0 testname=kaikkiIsanLapsetTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    if(!assertMyPointerEquals((char *)alan->lapset[1], (char *)bill) || !assertMyPointerEquals((char *)steve->isa, (char *)alan))
    {
        printf("%%TEST_FAILED%% time=0 testname=kaikkiIsanLapsetTesti (henkiloTesti) error=pointerit osoittavat eri kohtiin \n");
    }
    else
    {
        printf("kaikkiIsanLapsetTesti test passed\n");
    }
    
    destroyList();
}

int main(void) {
    printf("%%SUITE_STARTING%% henkiloTesti\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% suhdeTesti (henkiloTesti)\n");
    suhdeTesti();
    printf("%%TEST_FINISHED%% time=0 suhdeTesti (henkiloTesti) \n");

    printf("%%TEST_STARTED%% isaLapsiTesti (henkiloTesti)\n");
    isaLapsiTesti();
    printf("%%TEST_FINISHED%% time=0 isaLapsiTesti (henkiloTesti) \n");

    printf("%%TEST_STARTED%% aitiLapsiTesti (henkiloTesti)\n");
    aitiLapsiTesti();
    printf("%%TEST_FINISHED%% time=0 aitiLapsiTesti (henkiloTesti) \n");
       
    printf("%%TEST_STARTED%% kaikkiAidinLapsetTesti (henkiloTesti)\n");
    kaikkiAidinLapsetTesti();
    printf("%%TEST_FINISHED%% time=0 kaikkiAidinLapsetTesti (henkiloTesti) \n");
    
    printf("%%TEST_STARTED%% kaikkiIsanLapsetTesti (henkiloTesti)\n");
    kaikkiIsanLapsetTesti();
    printf("%%TEST_FINISHED%% time=0 kaikkiIsanLapsetTesti (henkiloTesti) \n");
    
    
    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
