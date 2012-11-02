/* 
 * File:   HenkiloLista.h
 * Author: Anis Moubarik
 * Tiedosto määrittelee funktiot solmujen lisäämiseksi, poistamiseksi ja hakemiseksi sukupuusta. Käyttää henkilo.h funktioita.
 * Created on 20. lokakuuta 2011, 11:55
 */
#ifndef HENKILOLISTA_H
#define	HENKILOLISTA_H
#include "henkilo.h"

/**
 * Tarkoitus: Tulostaa linkitetty lista.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: Ei mitään
 */
extern void tulostaLista();

/**
 * Tarkoitus: Laskea linkitetyn listan solmujen määrä.
 * Parametrit: -
 * Palauttaa: Solmujen määrän kokonaislukuna
 * Muuttaa: Ei mitään
 */
extern int count();
/**
 * Tarkoitus: Lisätä henkilön linkitettyyn listaan.
 * Parametrit: henkilo* henk
 * Palauttaa: -
 * Muuttaa: Ei mitään
 */
extern void lisaa_listaan(henkilo* henk);
/**
 * Tarkoitus: Tuhota linkitetty listan.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: Tuhoaa listan.
 */
extern void destroyList();
/**
 * Tarkoitus: Etsiä henkilöä linkitetystä listasta.
 * Parametrit: char enimi[], char snimi[]
 * Palauttaa: currentin jos henkilö löytyy, nullin jo ei.
 * Muuttaa: Ei mitään
 */
extern henkilo* hae(char enimi[], char snimi[]);
/**
 * Tarkoitus: Palauttaa linkitetyn listan headin.
 * Parametrit: -
 * Palauttaa: Listan headin.
 * Muuttaa: Ei mitään
 */
extern henkilo* getHead();
/**
 * Tarkoitus: Hakee currentin edellisen
 * Parametrit: char enimi[], char snimi[]
 * Palauttaa: currentin nextin.
 * Muuttaa: currentin
 */
henkilo* haeEdellinen(char enimi[], char snimi[]);
/**
 * Tarkoitus: Tuhoaa yksittäisen listasolmun
 * Parametrit: henkilo *h
 * Palauttaa: -
 * Muuttaa: poistaa henkilön listasta.
 */
extern void tuhoa_solmu(henkilo *h);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HENKILOLISTA_H */
