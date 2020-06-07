#include "studente.h"

studente *CreaStudente(/*int matricola*/ char *matricola, char *titolo){
    studente *nuovostud = (studente *)malloc(sizeof(studente));
    if(!nuovostud) return NULL;

    //nuovostud->matricola = matricola;
    strcpy(nuovostud->libroprestato, matricola);
    strcpy(nuovostud->libroprestato, titolo);
    nuovostud->next = NULL;
    return nuovostud;
}


studente *InserisciCodaStudente(studente *listaStudenti,/*int matricola*/ char *matricola, char *titolo){
    if(listaStudenti == NULL) return CreaStudente(matricola, titolo);
    listaStudenti->next = InserisciCodaStudente(listaStudenti->next, matricola, titolo);
    return listaStudenti;
}


studente *EliminaStudente(/*int matricola*/char *matricola, studente *listaStudenti){
    if(!listaStudenti) return NULL;
    /*if(listaStudenti->matricola == matricola)*/
    if (strcmp(/*matricola,*/ listaStudenti->matricola,matricola)) return EliminaStudente(matricola, listaStudenti->next);
    listaStudenti->next = EliminaStudente (matricola, listaStudenti->next);
    return listaStudenti;
}


void stampaListaStudenti(studente *listaStudenti){
    if(listaStudenti != NULL){
        printf("LA MATRICOLA ");
        printf(" %s ", listaStudenti->matricola);
        printf("HA IN PRESTITO IL LIBRO :  ");
        printf(" %s\n ", listaStudenti->libroprestato);
        stampaListaStudenti(listaStudenti->next);
    }
}


bool controllainstudenti(/*int matricola*/char *matricola, studente *listaStudenti){
    if(listaStudenti != NULL){
        //if(matricola == listaStudenti->matricola){
        if (strcmp( matricola, listaStudenti->matricola)){
            return true;
        }
        controllainstudenti(matricola, listaStudenti->next);
    }else
    {
        return false;
    }
}


bool possiedelibro(/*int matricola*/char *matricola, char *titolo, studente *listaStudenti){
    if(listaStudenti != NULL){
        //if(matricola == listaStudenti->matricola){
        if (strcmp(matricola, listaStudenti->matricola)){
            if(strcmp(titolo, listaStudenti->libroprestato) == 0){
                return true;
            }
        }
        possiedelibro(matricola, titolo, listaStudenti->next);
    }else
    {
        return false;
    }

}

int LunghezzaListaStudenti(studente *lista){
  if(!lista) return 0;
  return(1 + LunghezzaListaStudenti(lista->next));
}
