#include <stdlib.h>
#include "hash.h"

#define SIZE 3


THash chained_hash_create(unsigned long size){
    THash hash;
    int i;
    
    hash.bucket=(TList*)malloc(size*sizeof(TList));
    hash.size=size;
    for(i=0;i<size;i++)
       hash.bucket[i]=list_create();
    
    return hash;
}

THash chained_hash_destroy(THash hash){
    int i;
    
    for(i=0;i<hash.size;i++)
       hash.bucket[i]=list_destroy(hash.bucket[i]);
    
    free(hash.bucket);
    hash.bucket=NULL;
    hash.size=0;

    return hash;    
}

TNode* chained_hash_search(THash hash, TKey key)
{
	return list_search(hash.bucket[f_hash(key)], key);
}


void chained_hash_insert(THash hash, TInfo info)
{
  hash.bucket[f_hash(info.key)]=list_insert(hash.bucket[f_hash(info.key)], info);
}


void chained_hash_delete(THash hash, TKey key)
{
  hash.bucket[f_hash(key)]=list_delete(hash.bucket[f_hash(key)], key);
}


void chained_hash_print(THash hash) {
    int i;
    TList l = list_create();

    for(i=0;i<hash.size;i++) {
       TList curr=hash.bucket[i];
       l = list_merge(l, curr);
	 }
    list_print(l);
    l = list_destroy(l);
}

/*Funzione da implementare*/
int f_hash(TKey key)
{
    char primo,ultimo;
    primo = key[0];
    ultimo = key[MAXKEY-1];
    return (primo*ultimo)%SIZE;
}
