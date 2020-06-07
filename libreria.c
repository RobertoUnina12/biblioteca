#include "libreria.h"


libro *CreaLibro(char *titolo, int disponibilita_volumi){
    libro *nuovoLibro = (libro *)malloc(sizeof(libro));
    if(!nuovoLibro) return NULL;

    strcpy(nuovoLibro->titolo, titolo);
    nuovoLibro->disponibilita_volumi = disponibilita_volumi;
    nuovoLibro->next = NULL;

    return nuovoLibro;
}


libro *InserisciCoda(libro *libreria, char *titolo, int disponibilita_volumi){
    if(libreria == NULL) return CreaLibro(titolo, disponibilita_volumi);
    libreria->next = InserisciCoda(libreria->next, titolo, disponibilita_volumi);
    return libreria;
 }

void StampaLibri(libro *libreria){
     if(libreria != NULL){

         printf("%s \t | %d\n", libreria->titolo, libreria->disponibilita_volumi);
         StampaLibri(libreria->next);
     }
 }

int LunghezzaLista(libro *lista){
  if(!lista) return 0;
  return(1 + LunghezzaLista(lista->next));
}

bool libroinlista(char *titolo, libro *libreria){
    if(libreria != NULL){
        if(strcmp(titolo, libreria->titolo) == 0){
            printf(" LIBRO TROVATO !!!\n");
            return true;
        }
        libroinlista(titolo, libreria->next);
    }
}


libro *getlibro(char *titolo, libro *libreria){
    libro *tmp = (libro *)malloc(sizeof(libro));
    if(libreria != NULL){
        if(strcmp(titolo, libreria->titolo) == 0){
            strcpy(tmp->titolo, libreria->titolo);
            tmp->disponibilita_volumi = libreria->disponibilita_volumi;
            return tmp;
        }else{
            getlibro(titolo, libreria->next);
        }
    }
}

void modificalibro(libro *nuovo, libro *libreria){
    if(libreria != NULL){
        if(strcmp(nuovo->titolo, libreria->titolo) == 0){
            libreria->disponibilita_volumi = nuovo->disponibilita_volumi;
            printf("\n LIBRERIA AGGIORNATA \n");
        }
        modificalibro(nuovo, libreria->next);
    }
}

void StampaLibriStudente(libro *libreria){
     if(libreria != NULL){
         printf("%s \n", libreria->titolo);
         StampaLibriStudente(libreria->next);
     }
}
