#ifndef STUDENTE_H_INCLUDED
#define STUDENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 100

typedef struct studente{
    /*int matricola*/
    char titolo[max];
    char matricola[max];
    char libroprestato[max];
    struct studente *next;
}studente;


studente *CreaStudente(/*int matricola*/char *matricola, char *titolo);
studente *InserisciCodaStudente(studente *listaStudenti, /*int matricola*/ char *matricola, char *titolo);
studente *EliminaStudente(/*int matricola*/char *matricola, studente *listaStudenti);
void stampaListaStudenti(studente *listaStudenti);
bool controllainstudenti(/*int matricola*/char *matricola, studente *listaStudenti);
int LunghezzaListaStudenti(studente *lista);


#endif // STUDENTE_H_INCLUDED
