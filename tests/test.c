/*
 * File:   test.c
 * Author: moubarik
 *
 * Created on 4.11.2011, 17:25:01
 */

#include <stdlib.h>
//#include <stdbool.h>
#include "test.h"
#include <string.h>
#include <stdio.h>
#include "../henkilo.h"
#include "../TiedostonLukuKirjoitus.h"

void henkiloidenAlustus() {
    lueSukupuuTiedostosta("testisukupuu.txt");
}

bool assertMyNull(void* pointer)
{
    if(pointer)
    {
        //printf("Pointer was not null");
        return false;
    }
    return true;
}

bool assertMyPointerEquals(char* pointer, char* expected)
{
    if(strcmp(pointer, expected) == 0)
    {
        return true;
    }
    
    return false;
}


bool assertMyIntEquals(int expected, int value)
{
    if(expected != value)
    {
        //printf("Expected %d, got %d \n", expected, value);
        return false;
    }
    return true;
}

bool assertMyStringEquals(char* expected, char* value)
{
    if(strcmp(expected, value) != 0)
    {
        //printf("Expected %s, got %s\n", expected, value);
        return false;
    }
    return true;
}

