#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "richiesta.h"
#include "studente.h"
#include "libreria.h"

#define max 100

int main()
{
    libro *libreria = NULL;
    studente *listaStudenti = NULL;
    richiesta *listarich =NULL, *current;
    int scelta,disponibilita_volumi,matricola;
    char titolo[max];
    int i;
    printf("INSERISCI 15 LIBRI ALL'INTERNO DELLA BIBLIOTECA \n");
    for (i=0; i<2; i++)
    {
        printf("INSERISCI IL %d LIBRO : ",i+1);
        scanf("%s",titolo);
        printf("INSERISCI IL NUMERO DEI LIBRI : ");
        scanf("%d",&disponibilita_volumi);
        libreria = InserisciCoda(libreria,titolo,disponibilita_volumi);
    }
    /*libreria = InserisciCoda(libreria,"Orgoglio_e_Pregiudizio", 5);
    libreria = InserisciCoda(libreria,"Il_Signore_degli_Anelli", 6);
    libreria = InserisciCoda(libreria,"Il_Profeta", 9);
    libreria = InserisciCoda(libreria,"Harry_Potter", 9);
    libreria = InserisciCoda(libreria,"Se_questo_è_un_uomo", 6);
    libreria = InserisciCoda(libreria,"Cime_Tempestose", 5);
    libreria = InserisciCoda(libreria,"1984", 4);
    libreria = InserisciCoda(libreria,"I_PromessiSposi", 4);
    libreria = InserisciCoda(libreria,"La_Divina_Commedia ", 1);
    libreria = InserisciCoda(libreria,"Piccole_Donne", 6);
    libreria = InserisciCoda(libreria,"Lessico_Familiare", 7);
    libreria = InserisciCoda(libreria,"Comma_22", 6);
    libreria = InserisciCoda(libreria,"Il_Giardino_dei_Finzi_Contini", 9);
    libreria = InserisciCoda(libreria,"Il_Nome_della_Rosa", 1);
    libreria = InserisciCoda(libreria,"Il_Gattopardo", 4);
*/

    do{
        printf("\n1.Mostra libri in biblioteca\n2.Richiedi libro\n3.Restituisci libro\n4.Mostra lista richieste\n5.Esegui richiesta\n6.Mostra elenco prestiti\n\n0.Esci\n");
        scanf("%d", &scelta);
        switch(scelta){
            case 1: //mostra elenco
                system("cls");
                puts("");
                StampaLibri(libreria);
                break;
            case 2: // richiedi libro
                system("cls");
                printf("\nInserire matricola:\n");
                scanf("%d", &matricola);
                puts("");
                puts("Elenco libri:");
                StampaLibri(libreria);
                printf("\nInserire il titolo del libro richiesto:\n");
                scanf("%s", titolo);
                if(libroinlista(titolo, libreria) == true){
                    listarich = InserisciCodarichiesta(listarich,titolo, false, matricola, (LunghezzaListarich(listarich))+1);
                }else{
                    printf("\nLibro non trovato\n");
                }
                break;
            case 3: //restituisci libro
                system("cls");
                printf("\nInserire matricola:\n");
                scanf("%d", &matricola);
                puts("");
                puts("Elenco libri:");
                StampaLibri(libreria);
                printf("\nInserire il titolo del libro da restituire:\n");
                scanf("%s", &titolo);
                if(libroinlista(titolo, libreria) == true){
                    listarich = InserisciCodarichiesta(listarich,titolo, true, matricola, (LunghezzaListarich(listarich))+1);
                }else{
                    printf("\nLibro non trovato\n");
                }
                break;
            case 4: //elenco richieste
                system("cls");
                Stamparich(listarich);
                break;
            case 5: //esegui richiesta
                system("cls");
                if(listarich == NULL){
                    printf("Nessuna richiesta \n");
                    break;
                }else{
                    current = listarich;
                }
                int tmp = current->numero;
                libro *book = getlibro(current->titolo, libreria);
                    if(current->tipo == false){//PRESTITO
                        if((controllainstudenti(current->matricola, listaStudenti))==true){ //possiede giÃ  un libro
                            printf("%s possiede un altro libro\n", current->matricola);
                            listarich = Eliminarich(tmp, listarich);
                            break;
                        }else{ //non possiede libro
                            if(book->disponibilita_volumi == 0){//libro non disponibile
                                printf("%s non disponibile\n", current->titolo);
                                listarich = Eliminarich(tmp, listarich);
                                break;
                            }else{ //libro disponibile
                                (book->disponibilita_volumi)--;
                                modificalibro(book, libreria);
                                listaStudenti = InserisciCodaStudente(listaStudenti, current->matricola, book->titolo);
                                printf("%s dato in prestito ad %d",book->titolo, current->matricola);
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
                            printf("%s restituito dalla matricola %d|\n ", book->titolo, current->matricola);
                            listaStudenti = EliminaStudente(current->matricola, listaStudenti);
                            listarich = Eliminarich(tmp, listarich);
                            break;
                        }else{
                            printf("Errore : %d non possiede %s\n", current->matricola, current->titolo);
                            listarich = Eliminarich(tmp, listarich);
                            break;
                        }
                    }
                //listarich = Eliminarich(tmp, listarich);
                break;
            case 6:
                system("cls");
                if(LunghezzaListaStudenti(listaStudenti) == 0){
                    puts("Nessun prestito");
                    break;
                }else {
                    stampaListaStudenti(listaStudenti);
                }
            case 0:
                break;
            default:
                printf("\nScelta invalida\n");
                break;
        }
    }while(scelta != 0);
    return 0;
}

