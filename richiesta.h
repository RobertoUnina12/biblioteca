#ifndef RICHIESTA_H_INCLUDED
#define RICHIESTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "studente.h"

#define max 100

typedef struct richiesta{
    int numero;
    char titolo[max];
    bool tipo;       //false chiedi | true restituisci
    int matricola;
    struct richiesta *next;
}richiesta;

int LunghezzaListarich(richiesta *listarich);

richiesta *crearichiesta(richiesta *listarich, char *titolo, bool tipo, int matricola, int numero);

richiesta *InserisciCodarichiesta(richiesta *listarichieste, char *titolo, bool tipo, int matricola, int numero);

void Stamparich(richiesta *listarich);

richiesta *daeseguire(richiesta *listarich);

richiesta *Eliminarich(int numero, richiesta* listarich);

bool possiedelibro(int matricola, char *titolo, studente *listaStudenti);

richiesta *minima(richiesta *listarich);

#endif // RICHIESTA_H_INCLUDED
