/* 
 * File:   Tulostus.h
 * Author: Anis Moubarik & Anna Hietanen
 * Tiedosto määrittelee ohjelman tulostamista koskevat funktiot.
 * Created on 1. marraskuuta 2011, 18:23
 */

#ifndef TULOSTUS_H
#define	TULOSTUS_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Tarkoitus: Tulostaa tulostusvalikon.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: -
 */
extern void tulostus();
/**
 * Tarkoitus: Tulostaa käyttäjän syöttämän henkilön jälkeläiset.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: -
 */
void tulostaLapset();
/**
 * Tarkoitus: Tulostaa käyttäjän syöttämän henkilön esivanhemmat.
 * Parametrit: henkilo *hlo
 * Palauttaa: -
 * Muuttaa: -
 */
void tulostaVanhemmat(henkilo *hlo);
/**
 * Tarkoitus: Tulostaa käyttäjän syöttämän henkilön rekisteröidyt suhteet.
 * Parametrit: henkilo *hlo
 * Palauttaa: -
 * Muuttaa: -
 */
void tulostaSuhde(henkilo *hlo);


#ifdef	__cplusplus
}
#endif

#endif	/* TULOSTUS_H */

