# Environment 
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
CFLAGS=-O3 -Wall -pedantic -std=c99

SOURCES=main.c HenkiloLista.h TiedostonLukuKirjoitus.h henkilo.h

all: sukupuu test
	chmod 700 ./sukupuu

sukupuu: main.o HenkiloLista.o Tulostus.o TiedostonLukuKirjoitus.o henkilo.o
	gcc $(CFLAGS) main.o HenkiloLista.o Tulostus.o TiedostonLukuKirjoitus.o henkilo.o -o sukupuu

main.o: main.c
	gcc $(CFLAGS) -c main.c

HenkiloLista.o: HenkiloLista.c HenkiloLista.h
	gcc $(CFLAGS) -c HenkiloLista.c

TiedostonLukuKirjoitus.o: TiedostonLukuKirjoitus.c TiedostonLukuKirjoitus.h
	gcc $(CFLAGS) -c TiedostonLukuKirjoitus.c

henkilo.o: henkilo.c henkilo.h
	gcc $(CFLAGS) -c henkilo.c

Tulostus.o: Tulostus.c Tulostus.h
	gcc $(CFLAGS) -c Tulostus.c

test:
	echo "LETS TEST"
	cd tests/ && make testi-henkiloLista && make testi-henkilo
	
clean:
	rm -f main.o HenkiloLista.o TiedostonLukuKirjoitus.o henkilo.o Tulostus.o tests/henkiloTesti.o tests/henkiloListaTesti.o tests/test.o
