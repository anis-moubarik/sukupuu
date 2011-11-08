# Environment 
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
CFLAGS=-O3 -Wall -pedantic -std=c99
FILES=../henkilo.o ../TiedostonLukuKirjoitus.o ../HenkiloLista.o ../Tulostus.o


testi-henkiloLista: test.o henkiloListaTesti.o $(FILES)
	gcc $(CFLAGS) henkiloListaTesti.o test.o $(FILES) -o testi-henkiloLista

testi-henkilo: test.o henkiloTesti.o $(FILES)
	gcc $(CFLAGS) henkiloTesti.o test.o $(FILES) -o testi-henkilo
	
henkiloTesti.o: henkiloTesti.c
	gcc $(CFLAGS) -c henkiloTesti.c

henkiloListaTesti.o: henkiloListaTesti.c
	gcc $(CFLAGS) -c henkiloListaTesti.c

test.o: test.c test.h
	gcc $(CFLAGS) -c test.c test.h

clean: 
	rm -f henkiloTesti.o henkiloListaTesti.o test.o
