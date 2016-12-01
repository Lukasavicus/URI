// Lukasavicus 1113

#include <stdio.h>

main (){

  int n1 =0 , n2 = 1, i;

  while (n1 != n2) {
  scanf("%d %d", &n1, &n2);

  if(n1 > n2)
    printf ("Decrescente\n");

  if(n2 > n1)
    printf ("Crescente\n");
  }

}