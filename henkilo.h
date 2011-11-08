/* 
 * File:   henkilo.h
 * Author: Anis Moubarik
 * Tiedosto määrittelee henkilön lisäämistä sekä henkilön tietojen ja suhteiden muokkaamista koskevat funktiot. Käytettävät funkiot on listattu ja määritelty alla.
 * Tiedosto ei käytä muiden tiedostojen funktioita.
 * Created on 17. lokakuuta 2011, 12:08
 */
#ifndef HENKILO_H
#define	HENKILO_H



/*ihmisen määrittely*/
typedef struct ihminen{
    char syntymaaika[12];
    char kuolinaika[12];
    int lastenlkm;
    struct ihminen* isa;
    struct ihminen* aiti;
    struct ihminen* lapset[20];
    struct ihminen* suhde;
    char enimi[50];
    char snimi[50];
    struct ihminen* next;
} henkilo;


/**
 * Tarkoitus: Ottaa käyttäjän syötteestä henkilön tiedot ja lisää ne henkilölle.
 * Parametrit: -
 * Palauttaa: hlo
 * Muuttaa: Ei mitään
 */
extern henkilo* otaJaLisaaHenkilonTiedot();


/**
 * Tarkoitus: Muokata yksittäisen henkilön tietoja.
 * Parametrit: henkilo* hlo
 * Palauttaa: Henkilö pointerin
 * Muuttaa: Henkilön tietoja
 */
extern void muokkaaHenkilonTietoja(henkilo* hlo);


/**
 * Tarkoitus: Ottaa käyttäjän syötteestä henkilön tiedot ja tarkistaa löytyykö henkilö.
 * Parametrit: -
 * Palauttaa: 1 tai 0
 * Muuttaa: Ei mitään
 */

extern int henkilonMuokkaus();


/**
 * Tarkoitus: Lisää linkitettyyn listaan hlo
 * Parametrit: henkilo *hlo
 * Palauttaa: Henkilö pointerin
 * Muuttaa: -
 */
 
extern void lisaa_henkilo(henkilo *hlo);

/**
 * Tarkoitus: Lisää henkilölle suhteen (isän, äidin tai partnerin), mikäli henkilö löytyy.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: Henkilön suhteita.
 */
extern void lisaaSuhde();


/**
 * Tarkoitus: Muuttaa henkilön parisuhdetta.
 * Parametrit: henkilo* hlo, henkilo* partneri
 * Palauttaa: -
 * Muuttaa: Henkilön partnerin.
 */
extern void muutaSuhde(henkilo* hlo, henkilo* partneri);
/**
 * Tarkoitus: Lisätä henkilölle isä.
 * Parametrit: henkilo* lapsi, henkilo *isa
 * Palauttaa: -
 * Muuttaa: Henkilön isää.
 */
extern void lisaaIsa(henkilo* lapsi, henkilo *isa);
/**
 * Tarkoitus: Lisätä henkilölle äiti.
 * Parametrit: henkilo* lapsi, henkilo *aiti
 * Palauttaa: -
 * Muuttaa: Henkilön äitiä.
 */
extern void lisaaAiti(henkilo* lapsi, henkilo *aiti);
/**
 * Tarkoitus: Lisätä henkilölle rekisteröity suhde.
 * Parametrit: henkilo* hlo, henkilo *suhde
 * Palauttaa: -
 * Muuttaa: Henkilön parisuhdetta.
 */
extern void lisaaRekisteroitySuhde(henkilo* hlo, henkilo *suhde);






#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HENKILO_H */
