/* 
 * File:   HenkiloLista.c
 * Author: Anis Moubarik
 * Tiedosto sisältää funktioita solmujen lisäämiseksi, poistamiseksi ja hakemiseksi sukupuusta. Käyttää hyväksi HenkiloLista.h.
 * Created on 20. lokakuuta 2011, 11:55
 */

#include <stdio.h>
#include <stdlib.h>
#include "HenkiloLista.h"
#include "string.h"



struct solmu{
    henkilo hlo;
    struct solmu *next;
};


henkilo *head = NULL;

henkilo* getHead()
{
    return head;
}

void setHead(henkilo *hlo)
{
    head = hlo;
}

void lisaa_listaan(henkilo* henk)
{
    henkilo *temp = (henkilo *)calloc(1, sizeof(henkilo));
    if(temp == NULL)
    {
        printf("Muistinvaraus ei onnistunut\n");
        exit(1);
    }
    *temp = *henk;

    
    if(head == NULL)
    {
        head = temp;
        head->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}


henkilo* hae(char enimi[], char snimi[])
{
    henkilo* current;
    char etunimi[50];
    char sukunimi[50];
    strcpy(etunimi, enimi);
    strcpy(sukunimi, snimi);
    current = head;
    while(current != NULL)
    {
        if(strcmp(current->snimi, snimi) == 0 && strcmp(current->enimi, enimi) == 0)
        {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

henkilo* haeEdellinen(char enimi[], char snimi[])
{
    henkilo* current;
    char etunimi[50];
    char sukunimi[50];
    strcpy(etunimi, enimi);
    strcpy(sukunimi, snimi);
    current = head;
    while(current != NULL)
    {
        if(current->next == NULL)
        {
            return NULL;
        }
        if(strcmp(current->next->snimi, snimi) == 0 && strcmp(current->next->enimi, enimi) == 0)
        {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}


void tuhoa_solmu(henkilo *h)
{
    char enimi[50], snimi[50];
    strcpy(enimi, h->enimi);
    strcpy(snimi, h->snimi);
    henkilo* edellinen = haeEdellinen(enimi, snimi);
    if(h->next != NULL && edellinen != NULL)
    {
        edellinen->next = h->next;
        free(h);
    }
    else if(h->next == NULL && edellinen != NULL)
    {
        edellinen->next = NULL;
        free(h);
    }
    else
    {
        setHead(h->next);
        free(h);
    }
}

void destroyList()
{
    henkilo *tmp;
    while(head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    free(tmp);
}




void tulostaLista()
{
    henkilo *currentnode;
    currentnode = head;
    
    while(currentnode != NULL)
    {
        printf("%s %s\n", currentnode->enimi, currentnode->snimi);
        currentnode = currentnode->next;
    }
    
}


int count()
{
    henkilo* n;
    int count  = 0;
    n = head;
    
    while(n != NULL)
    {
        n = n->next;
        count++;
    }
    
    return count;
}

