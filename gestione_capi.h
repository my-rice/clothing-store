#ifndef GESTIONE_CAPI_H
#define GESTIONE_CAPI_H

#include "hash.h"

/*La funzione legge il dato TInfo e inserisce un nuovo nodo nella tabella hash.
  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti. (La funzione viene già fornita)*/
int inserisci_capo (THash abbigliamento);

/*La funzione legge il codice del capo di abbigliamento e l'operazione da effettuare.
  Successivamente cerca il capo di abbigliamento, se non viene trovato si restituisce -1,
  altrimenti si verifica se l'operazione scelta è fattibile. Se l'operazione è di
  vendita ed il capo di abbigliamento si trova nello stato 1, si pone lo stato del
  capo di abbigliamento a 2 e si restituisce 1, se lo stato è diverso da 1  si
  restituisce 0. Se l'operazione è di restituzione ed il capo di abbigliamento si
  trova nello stato 2, si pone lo stato del capo di abbigliamento a 3 e si
  restituisce 2, se lo stato è diverso da 2  si restituisce 0.*/
int vendita_restituzione_capo (THash abbigliamento);


/*La funzione legge la tipologia e la marca del capo di abbigliamento di interesse
  e ne calcola la quantità facendo uso della funzione ausiliaria
  int conta(TList list, char tipologia[], char marca[]). Alla fine stampa il numero
  di capi di abbigliamento di interesse. La funzione non restituisce alcun valore.*/
void conta_capi(THash abbigliamento);

/*La funzione calcola all'interno di una lista il numero di capi di una data
  tipologia e di una data marca. La funzione restituisce il numero di capi trovati
  nella lista (La funzione deve essere ricorsiva).*/
int conta(TList list, char tipologia[], char marca[]);

/*La funzione calcola il prezzo medio di tutti i capi che sono stati venduti.
  La funzione restituisce il prezzo medio calcolato.*/
float prezzo_medio_venduti(THash abbigliamento);

/*La funzione stampa, le informazioni di tutti i capi di abbigliamento in archivio.
  La funzione non restituisce alcun valore. (La funzione viene già fornita)*/
void stampa_capi (THash abbigliamenti);

#endif
