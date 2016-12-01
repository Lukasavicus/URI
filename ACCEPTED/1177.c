//Lukasavicus 1177

#include <stdio.h>
#define MAX 1000

void main(){

  int i, j;
  int val;

  scanf("%d", &val);

  for(i = 0, j = 0; i < MAX; i++, j =  ((j+1) % val) )
  	printf("N[%d] = %d\n", i, j);

}