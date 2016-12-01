// Lukasavicus 1115

#include <stdio.h>

main (){

  int n1 =1 , n2 = 1;

  while(n1 != 0 && n2 != 0) {
    scanf("%d %d", &n1, &n2);

    if(n1 != 0 && n2 != 0){
      if (n1 > 0 && n2 > 0)
        printf ("primeiro\n");
      else if (n1 < 0 && n2 > 0)
        printf ("segundo\n");
      else if (n1 < 0 && n2 < 0)
        printf ("terceiro\n");
      else
        printf ("quarto\n");

    }

  }

}