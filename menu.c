#include <stdio.h>
#include "menu.h"

int menu()
{
    int scelta,i;
    
    printf("-------------------------------------------------\n");
    printf("PROGRAMMA PER LA GESTIONE DI CAPI ABBIGLIAMENTO\n\n");
    printf("1. Inserisci un capo di abbigliamento \n");
    printf("2. Vendita/Restituzione\n");
    printf("3. Quantita' capi di una data tipologia e marca\n");
    printf("4. Prezzo medio dei capi venduti\n");
    printf("5. Stampa a video dei capi di abbigliemento\n");
    printf("0. EXIT\n\n");
    printf("-------------------------------------------------\n");
    printf("Selezionare la scelta [0-5]: ");
    scanf("%d", &scelta);
    while((scelta<0)||(scelta>5)){
       printf("ERRORE! valore non consentito\n");                        
       printf("Selezionare la scelta [0-5]: ");
       scanf("%d", &scelta);
    }
    return scelta;

   pause();
}

void clear_screen()
{
   system("CLS");
}

void pause()
{
   system("pause");
}
