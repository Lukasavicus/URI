// Lukasavicus 1101

#include <stdio.h>

main (){

  int n1 =1 , n2 = 1, aux, sum, i;

  while (n1 != 0 && n2 != 0) {
    scanf("%d %d", &n1, &n2);

    if (n1 > n2){
      aux = n1;
      n1 = n2;
      n2 = aux;
    }

    if(n1 != 0 && n2 != 0){
      for (i = n1, sum = 0; i <= n2; i++){
        printf ("%d ",i);
        sum += i;
      }
      
      printf ("Sum=%d\n", sum);
    }
  }

}