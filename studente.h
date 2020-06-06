#ifndef STUDENTE_H_INCLUDED
#define STUDENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 100

typedef struct studente{
    int matricola;
    char libroprestato[max];
    struct studente *next;
}studente;


studente *CreaStudente(int matricola, char *titolo);
studente *InserisciCodaStudente(studente *listaStudenti, int matricola, char *titolo);
studente *EliminaStudente(int matricola, studente *listaStudenti);
void stampaListaStudenti(studente *listaStudenti);
bool controllainstudenti(int matricola, studente *listaStudenti);
int LunghezzaListaStudenti(studente *lista);


#endif // STUDENTE_H_INCLUDED

/* non e' opportuno inizializzare la matricola con char* perche' assegnado una stringa
al parametro attuale tu vai a memorizzare nel puntatore a carattere quello presente come membro
della struttura l'indirizzo della stringa passata come parametro cosi' facendo puoi memorizzare
una sola stringa in tutta la lista perche' punteranno ad una stessa variabile. ovviamente
questo quando le funzioni sono ancora in gioco perche' quando le funzioni terminano quel puntatore puntera'
ad una zona di memoria inesistente.*/

