//Lukasavicus 1178

#include <stdio.h>
#define MAX 100

void main(){

  int i;
  double j;
  double val;

  scanf("%lf", &val);

  for(i = 0, j = val; i < MAX; i++, j /= 2)
  	printf("N[%d] = %.4lf\n", i, j);

}