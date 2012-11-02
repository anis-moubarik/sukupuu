/* 
 * File:   main.c
 * Author: Anis Moubarik & Anna Hietanen
 * Tiedosto sisältää ohjelman päävalikon.
 * Created on 17. lokakuuta 2011, 12:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "henkilo.h"
#include "HenkiloLista.h"
#include "TiedostonLukuKirjoitus.h"
#include "Tulostus.h"
#include <string.h>


int main_menu()
{
    int valinta = 0;
/*
    int valid[] = {1, 2, 3, 4, 5};
*/
    printf("1. Lisää henkilö.\n");
    printf("2. Muokkaa henkilön tietoja\n");
    printf("3. Lisää suhde\n");
    printf("4. Tulostus\n");
    printf("5. Lopeta\n");
/*
    printf("6. Poista lista\n");
    printf("7. Tallenna sukupuu\n\n");
*/
    scanf("%1d", &valinta);
    return valinta;
}


int main(int argc, char** argv) {
    
    int valinta = 0;
    lueSukupuuTiedostosta("sukupuu.txt");
    
    for (int i = 0; i < argc; i++)
    {
        if((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
        {
            printf("Ohjelma toimii ja saa syötteensä näppäimistöstä. Ohjelma eitoimi oikein mikäli syötetään ääkkösiä. "
"Ohjelmaan voi lisätä uuden henkilön painamalla numeroa yksi (1) ja syöttämällä kyseisen henkilön tiedot."
"Ohjelmassa olevan henkilön tietoja voi tarvittaessa muokata painamalla numeroa kaksi (2) ja syöttämällä henkilön tiedot uudestaan."
"Kahdelle henkilölle voi lisätä suhteen painamalla numeroa kolme (3)"
"Yksittäisen henkilön esivanhemmat, jälkeläiset tai rekisteröidyt suhteet saa\ tulostettua painamalla numeroa neljä(4). "
"Ohjelman saa lopetettua painamalla numeroa viisi (5)."
"Mikäli tarvitset lisätietoa, lue readme.txt.!\n\n");
            break;
        }
    }

    
    while(valinta != 5)
    {
        valinta = main_menu();
        switch (valinta) {
            case 1:
                system("clear");
                printf("Lisää henkilö\n\n");
                otaJaLisaaHenkilonTiedot();
                system("clear");
                printf("Henkilö lisätty\n\n");
                break;
                
            case 2:
                system("clear");
                printf("Muokkaa henkilön tietoja\n\n");
                int err = henkilonMuokkaus();
                if(err == 0)
                {
                    system("clear");
                    printf("Henkilöä ei löytynyt\n");
                }
                break;
                
            case 3:
                printf("Lisää suhde\n\n");
                lisaaSuhde();
                break;
                
            case 4:
                system("clear");
                printf("Tulostus:\n");
                tulostus();
                break;
                
            case 5:
                break;
                
/*
            case 6:
                destroyList();
                break;
                
            case 7:
                //system("clear");
                tallennaSukupuuTiedostoon();
                printf("Done\n");
                break;
*/
                
            default:
                system("clear");
                printf("Väärä valinta\n\n");
                
    
        }
    }
    
    
    
    tallennaSukupuuTiedostoon();
    destroyList();
    return (EXIT_SUCCESS);
}
