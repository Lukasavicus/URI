//Lukasavicus 1134

#include <stdio.h>

main(){
  int n1, n2;
  int Alcool = 0, Gasolina = 0, Diesel = 0;
  int opt;

  do{
    do{
      scanf ("%d", &n1);
    }while (n1 < 1|| n1 > 4);

    if(n1 == 1)
      Alcool++;
    else if (n1 == 2)
      Gasolina++;
    else if(n1 == 3)
      Diesel++;

    if(n1 == 4){
      printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", Alcool, Gasolina, Diesel);
      break;
    }

  }while(1);

}