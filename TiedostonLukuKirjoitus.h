/* 
 * File:   TiedostonLukuKirjoitus.h
 * Author: Vili Lehtinen & Anis Moubarik
 * Tiedosto määrittelee sukupuun tallentamista tiedostoon, lukemista tiedostosta ja sinne kirjoittamista koskevat funktiot.
 * Created on October 29, 2011, 11:27 PM
 */

#ifndef TIEDOSTONLUKUKIRJOITUS_H
#define	TIEDOSTONLUKUKIRJOITUS_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Tarkoitus: Lukee sukupuun tiedostosta.
 * Parametrit: char *filename
 * Palauttaa: -
 * Muuttaa: Ei mitään
 */
extern void lueSukupuuTiedostosta(char *filename);
/**
 * Tarkoitus: Kirjoittaa henkilön sukupuu tekstitiedostoon.
 * Parametrit: henkilo *h, char *filename
 * Palauttaa: -
 * Muuttaa: sukupuu.txt tiedostoa
 */
extern void kirjoitaHenkiloSukupuuTiedostoon(henkilo *h, char *filename);
/**
 * Tarkoitus: Tallentaa sukupuun tekstitiedostoon.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: tallentaa sukupuun sukupuu.txt
 */
extern void tallennaSukupuuTiedostoon();
/**
 * Tarkoitus: Kirjoittaa henkilön suhteen sukupuu tekstitiedostoon.
 * Parametrit: henkilo *h, char *filename
 * Palauttaa: -
 * Muuttaa: sukupuu.txt tiedostoa
 */
extern void kirjoitaSuhdeSukupuuTiedostoon(henkilo *h, char *filename);

extern void kirjoitaHenkiloSukupuuTiedostoon(henkilo *h, char *filename);

extern void kirjoitaIsaSukupuuTiedostoon(henkilo *h, char *filename);

extern void kirjoitaAitiSukupuuTiedostoon(henkilo *h, char *filename);


#ifdef	__cplusplus
}
#endif

#endif	/* TIEDOSTONLUKUKIRJOITUS_H */
