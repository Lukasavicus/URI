//Lukasavicus 1133

#include <stdio.h>

main(){
  int n1, n2, i;
  scanf ("%d %d", &n1, &n2);

  int aux;

  if(n2 < n1){
  	aux = n1;
  	n1 = n2;
  	n2 = aux;
  }

  for(i = n1+1; i < n2; i++)
    if((i % 5 == 2) || (i % 5 == 3))
      printf("%d\n", i);
}