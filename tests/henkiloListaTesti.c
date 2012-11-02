/* 
 * File:   henkiloListaTesti.c
 * Author: Anis Moubarik & Anna Hietanen
 * Tiedosto sisältää testejä ihmisten lisäämisestä sukupuuhun ja hakemisesta sukupuusta. Tiedosto hyödyntää test.h määriteltyjä funktioita ja testisukupuu.txt. Käyttää hyväksi HenkiloLista.h, Tulostus.h ja TiedostonLukuKirjoitus.h
 * 
 */
#include "test.h"
#include "../henkilo.h"
#include "../TiedostonLukuKirjoitus.h"
#include "../Tulostus.h"
#include "../HenkiloLista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*testi jossa lisätään yksi henkilö*/
void add_one();
/*testi jossa lisätään kymmenen henkilö*/
void add_ten();
/* testataan löytyykö henkilö*/
void hakuTestiLoytyy();
/*testataan mitä tapahtuu jos henkilöä ei löydy*/
void hakuTestiEiLoydy();

void add_one() {
    printf("HenkiloListaTesti add_one\n");
    henkilo *hlo = (henkilo *) calloc(1, sizeof (henkilo));
    strcpy(hlo->enimi, "Jesus");
    strcpy(hlo->snimi, "Kristus");
    strcpy(hlo->kuolinaika, "1.3.30");
    strcpy(hlo->syntymaaika, "1.1.-7");
    lisaa_listaan(hlo);
    henkilo *testi = getHead();
    if (assertMyNull(testi)) {
        printf("add_one test passed");
        printf("%%TEST_FAILED%% time=0 testname=add_one error=Yhden solmun lisääminen epäonnistui\n");
    }
    printf("add_one passed\n");
    tuhoa_solmu(hlo);
}

void add_ten() {
    printf("HenkiloListaTesti add_ten\n");
    henkiloidenAlustus();
    henkilo *testi = getHead();
    int i = 0;

    while (i < 10) {
        if (assertMyNull(testi)) {
            printf("%%TEST_FAILED%% time=0 testname=add_ten error=Kymmenen solmun lisääminen epäonnistui\n");
            return;
        }
        if (testi->next == NULL && i < 9) {
            printf("%%TEST_FAILED%% time=0 testname=add_ten error=Kymmenen solmun lisääminen epäonnistui\n");
            return;
        } else {
            testi = testi->next;
            i++;
        }
    }
    printf("add_ten test passed\n");
    destroyList();
}

void hakuTestiLoytyy() {
    printf("test hakuTestiLoytyy\n");
    henkiloidenAlustus();

    char enimi[50];
    char snimi[50];
    strcpy(enimi, "Jesus");
    strcpy(snimi, "Kristus");

    henkilo *h = hae(enimi, snimi);

    if (!assertMyStringEquals(h->enimi, enimi) || !assertMyStringEquals(h->snimi, snimi)) {
        printf("%%TEST_FAILED%% time=0 testname=hakuTestiLoytyy error=Henkilöä ei löytynyt\n");
    }

    printf("hakuTestiLoytyy passed\n");
    destroyList();
}

void hakuTestiEiLoydy() {
    printf("test hakuTestiEiLoydy\n");
    henkiloidenAlustus();

    char enimi[50];
    char snimi[50];
    strcpy(enimi, "Bill");
    strcpy(snimi, "Perapukama");

    henkilo *h = hae(enimi, snimi);
    
    if(h != NULL)
    {
        printf("%%TEST_FAILED%% time=0 testname=hakuTestiEiLoydy error=Henkilöä ei löytynyt\n");
    }

    printf("hakuTestiEiLoydy passed\n");
    destroyList();
}

int main(void) {
    printf("%%SUITE_STARTING%% test\n");
    printf("%%SUITE_STARTED%%\n");


    printf("%%TEST_STARTED%% add_one (henkiloListaTesti) \n");
    add_one();
    printf("%%TEST_FINISHED%% time=0 add_one (henkiloListaTesti) \n");

    printf("%%TEST_STARTED%% add_ten (henkiloListaTesti) \n");
    add_ten();
    printf("%%TEST_FINISHED%% time=0 add_ten (henkiloListaTesti) \n");
    
    printf("%%TEST_STARTED%% hakuTestiEiLoydy (henkiloListaTesti) \n");
    hakuTestiEiLoydy();
    printf("%%TEST_FINISHED%% time=0 hakuTestiEiLoydy \n");
    
    printf("%%TEST_STARTED%% hakuTestiLoytyy (henkiloListaTesti) \n");
    hakuTestiLoytyy();
    printf("%%TEST_FINISHED%% time=0 hakuTestiLoytyy (henkiloListaTesti) \n");
    


    printf("%%SUITE_FINISHED%% time=0\n");
    return (EXIT_SUCCESS);
}
