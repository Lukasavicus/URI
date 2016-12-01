//Lukasavicus 1173

#include <stdio.h>
#define MAX 10

void main(){

  int i, j;
  int val;

  scanf("%d", &val);

  for(i = 0, j = val; i < MAX; i++, j *= 2)
  	printf("N[%d] = %d\n", i, j);

}