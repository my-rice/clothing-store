#include <stdio.h>
#include "hash.h"
#include "info.h"
#include "bool.h"
#include "menu.h"
#include "gestione_capi.h"

#define SIZE 3
/*
 Si scriva un programma per la gestione di un archivio di un negozio di abbigliamento. I capi di abbigliamento che possono essere venduti sono:
•	Maglie
•	Giacche
•	Pantaloni
•	Gonne

I capi di abbigliamento in archivio possono trovarsi in 3 differenti stati:
•	Stato 1: capo di abbigliamento non venduto.
•	Stato 2: capo di abbigliamento venduto.
•	Stato 3: capo di abbigliamento restituito perché difettoso. 

I dati relativi ad ogni capo di abbigliamento sono:
•	Codice del capo di abbigliamento (Una stringa di 5 caratteri), campo chiave.
•	Topologia del capo di abbigliamento (Una stringa di 9 caratteri [Maglia / Giacca / Pantalone / Gonna]).
•	Marca del capo di abbigliamento (Una stringa di 15 caratteri)
•	Stato del capo di abbigliamento (Un intero [1 / 2 / 3])
•	Prezzo del capo di abbigliamento (Un reale)

Il programma memorizza i dati relativi ai conti correnti in una tabella hash con liste di collisione e con un bucket di dimensione 3. La funzione di hash fa il prodotto dei codici ascii del primo e dell’ultimo carattere della chiave caratteri della chiave e ne calcola il resto della divisione intera per 3. Il programma realizza le seguenti funzionalità:

•	Inserimento di un nuovo capo di abbigliamento. (Funzionalità già fornita)
•	Vendita o restituzione di un capo di abbigliamento.
•	Calcolo del numero totale di una particolare tipologia di capo di abbigliamento di una data marca.
•	Calcolo del totale del prezzo medio dei capi di abbigliamento venduti.
•	Stampa a video dei  capi di abbigliamento. (Funzionalità già fornita)

Lo studente per la realizzazione dell’applicazione ha a disposizione:
•	I file necessari alla creazione dell’intero progetto;
•	Le funzioni standard per la gestione della tabella hash che devono essere usate senza apportare loro alcuna modifica (né ai prototipi né alla loro implementazione fornita);
•	La definizione dei prototipi delle funzioni che devono essere implementate. 

I file forniti sono i seguenti:
•	info.h (da non modificare)
o	Contiene la definizione del tipo TInfo ed i prototipi delle funzioni per la sua gestione.
•	info.c (da non modificare)
o	Contiene l’implementazione delle funzioni per la gestione di TInfo.
•	list.h (da non modificare)
o	Contiene la definizione del tipo TList ed i prototipi delle funzioni per la gestione di TList (funzioni standard) 
•	list.c (da non modificare)
o	Contiene l’implementazione delle funzioni per la gestione di TList (funzioni standard)
•	hash.h (da non modificare)
o	Contiene la definizione del tipo THash ed i prototipi delle funzioni per la gestione di THash (funzioni standard)
•	hash.c (da completare)
o	Contiene l’implementazione delle funzioni per la gestione di THash (funzioni standard). Lo studente dovrà implementare la funzione int f_hash(TKey key);
•	menu.h (da non modificare)
o	Contiene i prototipi delle funzioni di interfaccia utente.
•	menu.c (da non modificare)
o	Contiene l’implementazione delle funzioni di interfaccia utente.
•	gestione_capi.h (da non modificare)
o	Contiene i prototipi delle funzioni richieste dall’applicazione:
	int inserisci_capo (THash abbigliamento);
•	La funzione legge il dato TInfo e inserisce un nuovo nodo nella tabella hash.  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti. (La funzione viene già fornita)
	int vendita_restituzione_capo (THash abbigliamento);
•	La funzione legge il codice del capo di abbigliamento e l’operazione da effettuare. Successivamente cerca il capo di abbigliamento, se non viene trovato si restituisce -1, altrimenti si verifica se l’operazione scelta è fattibile. Se l’operazione è di vendita ed il capo di abbigliamento si trova nello stato 1, si pone lo stato del capo di abbigliamento a 2 e si restituisce 1, se lo stato è diverso da 1  si restituisce 0. Se l’operazione è di restituzione ed il capo di abbigliamento si trova nello stato 2, si pone lo stato del capo di abbigliamento a 3 e si restituisce 2, se lo stato è diverso da 2  si restituisce 0.
	void conta_capi(THash abbigliamento);
•	La funzione legge la tipologia e la marca del capo di abbigliamento di interesse e ne calcola la quantità facendo uso della funzione ausiliaria int conta(TList list, char tipologia[], char marca[]). Alla fine stampa il numero di capi di abbigliamento di interesse. La funzione non restituisce alcun valore.
	int conta(TList list, char tipologia[], char marca[]);
•	La funzione calcola all'interno di una lista il numero di capi di una data tipologia e di una data marca. La funzione restituisce il numero di capi trovati nella lista (La funzione deve essere ricorsiva).
	float prezzo_medio_venduti(THash abbigliamento);
•	La funzione calcola il prezzo medio di tutti i capi che sono stati venduti. La funzione restituisce il prezzo medio calcolato.
	void stampa_capi (THash abbigliamento);
•	La funzione stampa, le informazioni di tutti i capi di abbigliamento in archivio. La funzione non restituisce alcun valore. (La funzione viene già fornita)
•	gestione_capi.c (da completare) 
o	Contiene l’implementazione delle funzioni richieste dall’applicazione
•	capi_abbigliamento.c (da completare)
o	Contiene il main del programma.

 
 
 */
int main()
{
    int scelta, inserimento, operazione;
    THash abbigliamento;

    /* Inizializzo le liste */
      abbigliamento = chained_hash_create(SIZE);


    /* Scelta della funzione per gestire l'archivio */
      scelta = 1;
      while(scelta){
          scelta = menu();
          if(scelta == 1 ){
              int inserimento = inserisci_capo (abbigliamento);
              if(inserimento == -1){
                  printf("Errore nell'inserimento\n");
              }else
                  printf("Inserimento corretto\n");
          }else if(scelta == 2){
              int  num = vendita_restituzione_capo (abbigliamento);
                printf("Num: %d\n",num);
          }else if(scelta == 3){
              conta_capi(abbigliamento);

          }else if(scelta == 4){
              printf("Prezzo medio capi venduti: %.3f.\n",prezzo_medio_venduti( abbigliamento));
          }else if(scelta == 5){
              stampa_capi (abbigliamento);

          }
              
          
          
      }
}
