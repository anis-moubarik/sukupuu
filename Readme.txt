-------------------------------------------------------------------------------------------------------
SUKUPUU
-------------------------------------------------------------------------------------------------------

Helsingin Yliopiston C-Ohjelmoinnin kurssiprojekti syksyllä 2011 URL: http://www.cs.helsinki.fi/node/62063

-------------------------------------------------------------------------------------------------------
Aihe/Tehtävä:
-------------------------------------------------------------------------------------------------------

Tee ohjelma, jonka avulla käyttäjä voi tallentaa sukupuun. Sukupuuhun voi tallettaa tietoja henkilöistä (nimi, syntymäaika, kuolinaika), näiden välisistä suhteista (sekä viralliset avioliitot että epäviralliset suhteet - jälkimmäiset halutaan tallettaa esim. sen vuoksi, että voidaan helposti pitää kirjaa lasten vanhemmista) ja suhteista syntyneistä lapsista. Yksinkertaisuuden vuoksi voit tehdä järjestelmän sellaiseksi, että jokaisella henkilöllä on eri nimi.

Ohjelmasi pitää tarjota ainakin seuraavat toiminnot:

henkilön lisäys (henkilö voidaan lisätä joko "itsenäisenä" tai joidenkin lapsena)
henkilön tietojen muutos
suhteen lisäys
annetun henkilön kaikkien jälkeläisten tulostus
annetun henkilön kaikkien esivanhempien tulostus
annetun henkilön kaikkien rekisteröityjen suhteiden tulostus.
Ohjelmasi voi luottaa syötettyjen tietojen järkevyyteen. Sen ei tarvitse esim. tarkistaa, että joku ei ole naimisissa kahden henkilön kanssa yhtä aikaa tai että jonkun lapsi ei ole vanhempi kuin henkilö itse.

Ohjelmasi täytyy käyttää dynaamista muistinvarausta - vain taulukoihin perustuvia ratkaisuja ei hyväksytä.


-------------------------------------------------------------------------------------------------------
Ryhmänjäsenet:
-------------------------------------------------------------------------------------------------------

Anis Moubarik
Anna Hietanen
Vili Lehtinen


-------------------------------------------------------------------------------------------------------
Työnjako:
-------------------------------------------------------------------------------------------------------

Anis Moubarik - Perusfunktiot, testit ja tulostus.
Anna Hietanen - Perusfunktiot, testit ja dokumentointi.
Vili Lehtinen - Tiedoston luku, kirjoitus ja tallennus.


-------------------------------------------------------------------------------------------------------
HELP
-------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------
Ohjelman rakenne:
-------------------------------------------------------------------------------------------------------

Tulostus.h

-määrittelyt Tulostus.c


Tulostus.c

-tulostaa jälkeläiset
-tulostaa esivanhemmat
-tulostaa rekisteröidyt suhteet
-tulostaa tulostusvalikon


HenkiloLista.h

-määrittelyt HenkiloLista.c


HenkiloLista.c

-linkitettyyn listaan lisääminen
-solmun (henkilön) haku listasta
-poistaa yksittäisen solmun
-tuhoaa koko listan
-tulostaa listan
-laskee solmujen (ihmisten) määrän listassa


TiedostonLukuKirjoitus.h

-määrittelyt TiedostonLukuKirjoitus.c


TiedostonLukuKirjoitus.c

-lukee sukupuun tekstitiedostosta
-tuntee tekstitiedoston koon
-kirjoittaa sukupuun tekstitiedostoon
-tallentaa sukupuun tekstitiedostoon


henkilo.h

-määrittelyt henkilo.c

henkilo.c

-henkilön lisäys
-henkilön tietojen muokkaaminen
-henkilön nimen muokkaaminen
-henkilön parisuhteiden muokkaaminen
-suhteen lisääminen henkilölle
-isän lisääminen henkilölle
-äidin lisääminen henkilölle
-parisuhteen lisääminen henkilölle


main.c

-sisältää ohjelman päävalikon


HenkiloListaTesti.c

-testi yhden ihmisen lisäämiseksi sukupuuhun
-testi kymmenen ihmisen lisäämiseksi sukupuuhun
-testi yhden löytämiseksi sukupuusta
-testi jolla ei löydetä ihmistä sukupuusta
-määrittelee HenkiloListaTesti.c

henkiloTesti.c

-testi suhteen tulostumisesta oikein
-testi isä-lapsi-suhteen tulostumisesta oikein
-testi äiti-lapsi-suhteen tulostumisesta oikein
-testi kaikkien äidin jälkeläisten tulostumisesta oikein
-testi kaikkien isän jälkeläisten tulostumisesta oikein

test.h

-määrittelyt test.c

test.c

-testi onko null
-testi onko pointterin osoitteet samat
-testi onko int sama
-testi onko string sama


Kaikki funktiot on kommentoitu .h tiedostoissa, paitsi ne joissa ei sellaista ole.
-------------------------------------------------------------------------------------------------------
Makefile ja testit
-------------------------------------------------------------------------------------------------------

Projektista löytyy Makefile jonka avulla voidaan käntää ja linkittää ohjelma kohdekoneelle.
Menemällä terminaalilla projektin juurikansioon ja ajamalla komennon make kääntyy ohjelma ja kansioon
pitäisi ilmestyä sukupuu ajettava tiedosto. Testi ohjelmat ilmestyvät tests kansioon, tiedostot voidaan
ajaa terminaalista käsin komennolla ./sukupuu tai testeille ./tests/testi-henkiloLista
./tests/testi-henkilo.
make clean siivoaa objektitiedostot kansioista pois.
make sukupuu, kääntää ja linkittää sukupuu ohjelman ilman testejä
make test, kääntää ja linkittää sukupuun testit ilmann sukupuuta, HUOM! Ei voida ajaa ilman sukupuun
objektitiedostoja.

-------------------------------------------------------------------------------------------------------
Käyttöohje:
-------------------------------------------------------------------------------------------------------

Sukupuuhun lisättävät ihmiset voidaan syöttää näppäimistöltä yksittäin tai vanhempien ja puolison kanssa. Ihmisille voi lisätä parisuhteen tai vanhemmat myös jälkikäteen päävalikon kautta. Myös yksilöiden muita tietoja on mahdollista muokata jälkikäteen päävalikon kautta. Ohjelmalla on mahdollista tulostaa tietyn yksilön esivanhemmat, jälkeläiset ja rekisteröidyt parisuhteet. Ohjelma tallentaa sukupuun automaattisesti tekstitiedostoon lopetettaessa ohjelma eli painettaessa numeroa viisi (5).
 
Ohjelma käynnistetään komennolla ./sukupuu
Ohjelmaan voi lisätä uuden henkilön painamalla numeroa yksi (1) ja syöttämällä kyseisen henkilön tiedot.
Ohjelmassa olevan henkilön tietoja voi tarvittaessa muokata painamalla numeroa kaksi (2) ja syöttämällä henkilön tiedot uudestaan.
Kahdelle henkilölle voi lisätä suhteen painamalla numeroa kolme (3). 
Yksittäisen henkilön esivanhemmat, jälkeläiset tai rekisteröidyt suhteet saa tulostettua painamalla numeroa neljä (4). 
Ohjelman saa lopetettua painamalla numeroa viisi (5).

Huom: Mikäli ohjelma loppuu muulla tavalla kuin numeroa viisi (5) painamalla sukupuu ei tallennu.

-------------------------------------------------------------------------------------------------------
Bugit:
-------------------------------------------------------------------------------------------------------
-Ääkköset eivät toimi/ihmeellistä toimintaa niiden kanssa.
-Ohjelma kaatuu, jos syötetään valinnaksi jotain muuta kuin numero.






