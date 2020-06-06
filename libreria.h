#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 100

typedef struct libro{
    char titolo[max];
    int disponibilita_volumi;
    struct libro *next;
}libro ;

libro *CreaLibro(char *titolo, int disponibilita_volumi);
libro *InserisciCoda(libro *libreria, char *titolo, int disponibilita_volumi);
void StampaLibri(libro *libreria);
int LunghezzaLista(libro *lista);
bool libroinlista(char *titolo, libro *libreria);
libro *getlibro(char *titolo, libro *libreria);
void modificalibro(libro *nuovo, libro *libreria);
void StampaLibriStudente(libro *libreria);




#endif // LIBRERIA_H_INCLUDED
