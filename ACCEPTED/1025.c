// Lukasavicus 1025

#include <stdio.h>
#include <stdlib.h>


#define MAX 10000

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int values[MAX];

int bin_search(int *v, const int vl, const int ini, const int fim){
    
   int mid = ini+((fim-ini)/2);

    //printf("vl:%d ini:%d fim:%d mid:%d [%d]\n", vl, ini, fim, mid, v[mid]);

   if(ini == (fim-1) && v[mid] != vl) return -1;

   if(v[mid] < vl)                return bin_search(v, vl, mid, fim);
   else if(v[mid] > vl)           return bin_search(v, vl, ini, mid);
   else                           return mid;
}

int main () {
   int item;
   int N, Q, i, j, reader, aux, iter = 0, index;

   while(scanf("%d %d", &N, &Q) && (N != 0 || Q != 0) ){
      printf("CASE# %d:\n", ++iter);
      for (i = 0; i < N; i++){
         scanf("%d", &values[i]);
      }
      qsort(values, N, sizeof(int), cmpfunc);
      for (i = 0; i < Q; i++){
         scanf("%d", &reader);
         //item = (int*) bsearch (&reader, values, N, sizeof (int), cmpfunc);
         item = bin_search(values, reader, 0, N);
         if( item != -1 ) {
            if (item == 0){
               printf("%d found at %d\n", reader, item+1);
            }
            else{
               j = item;
               while(values[j-1] == values[item]){
                  j--;
               }
               printf("%d found at %d\n", reader, j+1);
            }
         }
         else{
            printf("%d not found\n", reader);
         }
      }
   }

   
   return(0);
}