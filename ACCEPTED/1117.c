//Lukasavicus 1117

#include <stdio.h>

main(){
  double n1, n2;

  do{
    scanf("%lf", &n1);

    if(n1 < 0 || n1 > 10)
      printf ("nota invalida\n");
    else
      break;

  }while(1);

  do{
    scanf("%lf", &n2);

    if(n2 < 0 || n2 > 10)
      printf("nota invalida\n");
     else
      break;

  }while(1);

    printf("media = %.2lf\n", (n1+n2)/2);

}