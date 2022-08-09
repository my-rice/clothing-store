#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "info.h"

TInfo read_info()
{
   TInfo info;

   info.key = read_key();
   info.satellite = read_satellite();

   return info;
}


int equal(TKey x, TKey y)
{
   if (strcmp(x, y) == 0)
      return 1;
   else
      return 0;
}

int greater(TKey x, TKey y)
{
   if (strcmp(x, y) == 1)
      return 1;
   else
      return 0;
}

void print_info(TInfo x)
{
   print_key(x.key);
   print_satellite(x.satellite);   
   printf("\n");
}

void print_key(TKey k)
{
   printf("%6s  ", k);
}

void print_satellite(TSatellite s)
{
   printf("%10s  %16s  %2d  %7.2f", s.tipologia, s.marca, s.stato, s.prezzo);
}



TSatellite read_satellite()
{
   TSatellite sat;

   do{
   printf ("Inserisci la tipologia del capo di abbigliamenti [Maglia/Giacca/Pantalone/Gonna] ");
   scanf ("%s", sat.tipologia);
   } while (strcmp(sat.tipologia, "Maglia")!=0 && strcmp(sat.tipologia, "Giacca")!=0
   && strcmp(sat.tipologia, "Pantalone")!=0 && strcmp(sat.tipologia, "Gonna"));

   printf ("Inserisci la marca del capo di abbigliamento ");
   scanf ("%s", sat.marca);

   sat.stato = 1;

   do{
   printf ("Inserisci il prezzo [> 0] ");
   scanf ("%f", &sat.prezzo);
   }while (sat.prezzo <=0);
   
   return sat;
}


TKey read_key()
{
   TKey key;
   char tmp[MAXKEY];

   do
   {
   printf ("Inserisci il codice del capo di abbigliamento (5 caratteri): ");
   scanf ("%s", tmp);
   } while (strlen (tmp)!=MAXKEY-1);

   key = (TKey)malloc(MAXKEY*sizeof(TKey));
   strcpy (key, tmp);

   return key;

}

