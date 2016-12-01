//Lukasavicus 1174

#include <stdio.h>
#define MAX 100

void main(){

  int i;
  double v[MAX];

   for(i = 0; i < MAX; i++)
    scanf("%lf", &v[i]);

  for(i = 0; i < MAX; i++)
    if(v[i] <= 10.0)
      printf("A[%d] = %.1lf\n", i, v[i]);

}