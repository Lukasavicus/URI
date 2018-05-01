//Lukasavicus 1175

#include <stdio.h>
#define MAX 20

void main(){

  int i, j, aux;
  int v[MAX];

   for(i = 0; i < MAX; i++)
    scanf("%d", &v[i]);

  for(i = 0, j = MAX-1; i < j; i++, j--){
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
  }

  for(i = 0; i < MAX; i++)
    printf("N[%d] = %d\n", i, v[i]);

}