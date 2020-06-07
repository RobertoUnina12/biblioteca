#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "richiesta.h"
#include "studente.h"
#include "libreria.h"

#define max 100

int main()
{
    libro *libreria = NULL;
    studente *listaStudenti = NULL;
    richiesta *listarich = NULL, *current;
    int scelta,disponibilita_volumi;//,matricola;
    char titolo[max],matricola[max];
    printf("*** INIZIAMO CON IL POPOLARE LA LIBRERIA *** \n ");
    printf("*** CI SONO 15 LIBRI ALL'INTERNO DELLA BIBLIOTECA *** \n");
    libreria = InserisciCoda(libreria,"GUERRACIVILE", 25);
    libreria = InserisciCoda(libreria,"PICCOLEDONNE", 1);
    libreria = InserisciCoda(libreria,"CIAO", 3);
    libreria = InserisciCoda(libreria,"CIAOGIANDO", 0);
    libreria = InserisciCoda(libreria,"GRAZIE", 2);

    do{
        printf ("*********** MENU' BIBLIOTECA ***********\n");
        printf("\n 1.MOSTRA LIBRI IN BIBLIOTECA\n");
        printf("\n 2.RICHIEDI LIBRO\n");
        printf("\n 3.RESTITUISCI LIBRO \n");
        printf("\n 4.MOSTRA LISTA RICHIESTE\n");
        printf("\n 5.ESEGUI RICHIESTA\n");
        printf("\n 6.MOSTRA ELENCO PRESTITI\n");
        printf("\n 0.ESCI\n");
        printf("\n ***************************************** \n");
        scanf("%d", &scelta);
        switch(scelta){
            case 1: //mostra elenco
                system("cls");
                puts("");
                printf(" LIBRI \t | VOLUMI \n");
                StampaLibri(libreria);
                printf(" SCEGLI ORA LA PROSSIMA AZIONE : \n");
                break;
            case 2: // richiedi libro
                system("cls");
                printf("\n INSERISCI LA MATRICOLA : \n");
                scanf("%s", matricola);
                puts("");
                puts("ELENCO LIBRI : \n");
                puts("LIBRI \t | VOLUMI \n");
                StampaLibri(libreria);
                printf("\nINSERIRE TITOLO DEL LIBRO DA RICHIEDERE : \n");
                scanf("%s", titolo);
                if(libroinlista(titolo, libreria) == true){
                    listarich = InserisciCodarichiesta(listarich,titolo, false, matricola, (LunghezzaListarich(listarich))+1);
                }else{
                    printf("\nMI DISPIACE IL LIBRO CHE HAI RICHIESTO NON E' STATO TROVATO !! \n");
                }
                break;
            case 3: //restituisci libro
                system("cls");
                printf("\nINSERISCI LA MATRICOLA :\n");
                scanf("%s", /*&*/matricola);
                puts("");
                puts("ELENCO DEI LIBRI :");
                puts("LIBRI \t | VOLUMI \n");
                StampaLibri(libreria);
                printf("\nINSERIRE IL TITOLO DEL LIBRO DA RESTITUIRE :\n");
                scanf("%s", titolo);
                if(libroinlista(titolo, libreria) == true){
                    listarich = InserisciCodarichiesta(listarich,titolo, true, matricola, (LunghezzaListarich(listarich))+1);
                }else{
                    printf("\nLIBRO NON TROVATO MI DISPIACE !!\n");
                }
                break;
            case 4: //elenco richieste
                system("cls");
                Stamparich(listarich);
                break;
            case 5: //esegui richiesta
                system("cls");
                if(listarich == NULL){
                    printf("AL MOMENTO NON E' PRESENTE NESSUNA RICHIESTA. \n");
                    break;
                }else{
                    current = listarich;
                }
                int tmp = current->numero;
                libro *book = getlibro(current->titolo, libreria);
                    if(current->tipo == false){//PRESTITO
                        if((controllainstudenti(current->matricola, listaStudenti))== true){ //possiede già un libro
                            printf("AL MOMENTO %s POSSIEDE UN ALTRO LIBRO \n", current->matricola);
                            listarich = Eliminarich(tmp, listarich);
                            break;
                        }else{ //non possiede libro
                            if(book->disponibilita_volumi == 0){//libro non disponibile
                                printf("AL MOMENTO %s NON E' DISPONIBILE \n", current->titolo);
                                listarich = Eliminarich(tmp, listarich);
                                break;
                            }else{ //libro disponibile
                                (book->disponibilita_volumi)--;
                                modificalibro(book, libreria);
                                listaStudenti = InserisciCodaStudente(listaStudenti, current->matricola, book->titolo);
                                printf("IL LIBRO %s E' STATO DATO IN PRESTITO ALLA MATRICOLA : %s \n ",book->titolo, current->matricola);
                                listarich = Eliminarich(tmp, listarich);
                                free(book);
                                free(current);
                                break;
                            }
                        }
                    }
                    else{//RESTITUIRE
                       if((controllainstudenti(current->matricola, listaStudenti) == true) && (possiedelibro(current->matricola, current->titolo, listaStudenti)) == true){
                            (book->disponibilita_volumi)++;
                            modificalibro(book, libreria);
                            printf("IL LIBRO : %s E' STATO RESTITUITO DALLA MATRICOLA %s \n ", book->titolo, current->matricola);
                            listaStudenti = EliminaStudente(current->matricola, listaStudenti);
                            listarich = Eliminarich(tmp, listarich);
                            break;
                        }else{
                            printf("ERRORE : LA MATRICOLA %s NON POSSIEDE IL LIBRO %s\n", current->matricola, current->titolo);
                            listarich = Eliminarich(tmp, listarich);
                            break;
                        }
                    }
                listarich = Eliminarich(tmp, listarich); //QUI HO MODIFICATO.
                break;
            case 6:
                system("cls");
                if(LunghezzaListaStudenti(listaStudenti) == 0){
                    puts("AL MOMENTO NON E' STATO EFFETTUATO ALCUN PRESTITO");
                    break;
                }else {
                    stampaListaStudenti(listaStudenti);
                }
            case 0:
                break;
            default:
                printf("\n SCELTA NON VALIDA.. PER FAVORE RIPROVA .\n");
                break;
        }
    }while(scelta != 0);
    return 0;
}


