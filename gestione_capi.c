#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestione_capi.h"

#define SIZE 3

/*La funzione legge il dato TInfo e inserisce un nuovo nodo nella tabella hash.
  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti. (La funzione viene gi� fornita)*/
int inserisci_capo (THash abbigliamento)
{
   TInfo info;
   TNode *node;

   info = read_info();
   node = chained_hash_search(abbigliamento, info.key);
   if (node != NULL)
      return -1;

   chained_hash_insert(abbigliamento, info);
   return 1;
}

/*La funzione legge il codice del capo di abbigliamento e l'operazione da effettuare.
  Successivamente cerca il capo di abbigliamento, se non viene trovato si restituisce -1,
  altrimenti si verifica se l'operazione scelta � fattibile. Se l'operazione � di
  vendita ed il capo di abbigliamento si trova nello stato 1, si pone lo stato del
  capo di abbigliamento a 2 e si restituisce 1, se lo stato � diverso da 1  si
  restituisce 0. Se l'operazione � di restituzione ed il capo di abbigliamento si
  trova nello stato 2, si pone lo stato del capo di abbigliamento a 3 e si
  restituisce 2, se lo stato � diverso da 2  si restituisce 0.*/
int vendita_restituzione_capo (THash abbigliamento)
{
    int operazione;
    TKey capo = read_key();

    //unsigned h = f_hash(capo) % abbigliamento.size;
    TNode* node = chained_hash_search(abbigliamento, capo);
    if(node == NULL){
        //print_key(capo);
        return -1;
    }
    printf("Inserisci l'operazione: vendita(1) o restituzione (2)  \n");
    scanf("%d",&    operazione);
    if(operazione == 1){
        if(node->info.satellite.stato == 1){
            node->info.satellite.stato = 2;
            return 1;
        }else
            return 0;
    }
    else if(operazione == 2){
        if(node->info.satellite.stato == 2){
            node->info.satellite.stato = 3;
            return 2;
        }else
            return 0;
    }else
        printf("Operazione non valida\n");
}

/*La funzione legge la tipologia e la marca del capo di abbigliamento di interesse
  e ne calcola la quantit� facendo uso della funzione ausiliaria
  int conta(TList list, char tipologia[], char marca[]). Alla fine stampa il numero
  di capi di abbigliamento di interesse. La funzione non restituisce alcun valore.*/
void conta_capi(THash abbigliamento)
{
    int sum= 0;
    char tipologia[MAXTIP],marca[MAXCAR];
    
    printf("Inserisci la tipologia capo di abbigliamento:\n");
    scanf("%s",tipologia);
    
    printf("Inserisci la marca del capo di abbigliamento:\n");
    scanf("%s",marca);
    
    for(int i=0; i < abbigliamento.size; i++){
        sum += conta(m, tipologia, marca);
    }
    printf("N: %d\n",sum);
}

/*La funzione calcola all'interno di una lista il numero di capi di una data
  tipologia e di una data marca. La funzione restituisce il numero di capi trovati
  nella lista (La funzione deve essere ricorsiva).*/
int conta(TList list, char tipologia[], char marca[])
{
    if(list == NULL){
        return 0;
    }
    
    if(strcmp(tipologia,list->info.satellite.tipologia)==0 && strcmp(marca,list->info.satellite.marca)==0 ){
        return 1 + conta(list->link, tipologia, marca);
    }
    return conta(list->link, tipologia, marca);
}

/*La funzione calcola il prezzo medio di tutti i capi che sono stati venduti.
  La funzione restituisce il prezzo medio calcolato.*/
float prezzo_medio_venduti(THash abbigliamento)
{
    int sum = 0,contatore = 0;

    for(int i=0; i < abbigliamento.size; i++){
         for(TNode* m = abbigliamento.bucket[i];m!=NULL;m = m->link){
             if(m->info.satellite.stato == 2){
                 sum += m->info.satellite.prezzo;
                 contatore++;
             }
         }
    }
    if(contatore==0){
        return 0;
    }
        return (float)sum/contatore;
}

/*La funzione stampa, le informazioni di tutti i conti correnti in archivio.
  La funzione non restituisce alcun valore.(La funzione viene gi� fornita)*/
void stampa_capi (THash abbigliamento)
{
  printf ("I campi sono: \n");
  chained_hash_print(abbigliamento);
}

