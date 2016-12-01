//Lukasavicus 1118

#include <stdio.h>

main(){
  double n1, n2;
  int opt;

  do{
    do{
      scanf ("%lf", &n1);

      if(n1 < 0 || n1 > 10)
        printf ("nota invalida\n");
      else
        break;

    }while(1);

    do{
      scanf ("%lf", &n2);

      if(n2 < 0 || n2 > 10)
        printf ("nota invalida\n");
       else
        break;

    }while(1);

    printf ("media = %.2lf\n", (n1+n2)/2);

    do{
      printf ("novo calculo (1-sim 2-nao)\n");
      scanf("%d", &opt);

      if(opt == 1 || opt == 2)
        break;

    }while(1);

  }while(opt != 2);

}