/* 
 * File:   test.h
 * Author: Anis Moubarik & Anna Hietanen
 * Määrittelee testit tiedostossa test.c
 * Created on 4. marraskuuta 2011, 17:25
 */
#ifndef TEST_H
#define	TEST_H
#include <stdbool.h>
#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Tarkoitus: Testata onko null.
 * Parametrit: void* pointer
 * Palauttaa: true tai false
 * Muuttaa: - 
 */
extern bool assertMyNull(void* pointer);
/**
 * Tarkoitus: Testata ovatko pointereiden osoitteet samat
 * Parametrit: char* pointer, char* expected
 * Palauttaa: true tai false
 * Muuttaa: -
 */
extern bool assertMyPointerEquals(char* pointer, char* expected);
/**
 * Tarkoitus: Testata ovatko kokonaisluvut samat
 * Parametrit: int expected, int value
 * Palauttaa: true tai false
 * Muuttaa: -
 */
extern bool assertMyIntEquals(int expected, int value);
/**
 * Tarkoitus: Testata ovatko stringit samat
 * Parametrit: char* pointer, char* expected
 * Palauttaa: true tai false
 * Muuttaa: -
 */
extern bool assertMyStringEquals(char* expected, char* value);
/**
 * Tarkoitus: Testata toimiiko sukupuun luku tiedostosta.
 * Parametrit: -
 * Palauttaa: -
 * Muuttaa: -
 */
extern void henkiloidenAlustus();

#ifdef	__cplusplus
}
#endif

#endif	/* TEST_H */

