#include "richiesta.h"


richiesta *crearichiesta(richiesta *listarich, char *titolo, bool tipo, int matricola,int numero){
    richiesta *tmp;
    tmp = (richiesta *)malloc(sizeof(richiesta));
    if(!tmp) return NULL;
    else{
        tmp->next=NULL;
        strcpy(tmp->titolo, titolo);
        tmp->numero = numero;
        tmp->tipo = tipo;
        tmp->matricola = matricola;
        printf("Richiesta creata\n");
    }
    return tmp;
}


richiesta *InserisciCodarichiesta(richiesta *listarichieste, char *titolo, bool tipo, int matricola, int numero){
    if(listarichieste == NULL) return crearichiesta(listarichieste, titolo, tipo, matricola, numero);
    listarichieste->next = InserisciCodarichiesta(listarichieste->next, titolo, tipo, matricola, numero);
    return listarichieste;
}


void Stamparich(richiesta *listarich){
    if(listarich != NULL){
        printf("Numero:%d | Libro:%s | Tipo:%d | Studente:%d\n", listarich->numero, listarich->titolo, listarich->tipo, listarich->matricola);
        Stamparich(listarich->next);
    }
}



int LunghezzaListarich(richiesta *listarich){
  if(!listarich) return 0;
  return(1 + LunghezzaListarich(listarich->next));
}

richiesta *Eliminarich(int numero, richiesta* listarich){
    if(!listarich) return NULL;
    if(listarich->numero == numero) return Eliminarich(numero, listarich->next);
    listarich->next = Eliminarich (numero, listarich->next);
    return listarich;
}


richiesta *minima(richiesta *listarich){
    richiesta *minimo;
    if(listarich!=NULL){
        if(listarich->numero < LunghezzaListarich(listarich)){
            if(listarich->numero > listarich->next->numero){
            minimo = listarich;
            printf("new minimo %d", listarich->numero);
            }
        }else{
            minimo = listarich;
        }
        listarich = listarich->next;
    }else return minimo;
}
