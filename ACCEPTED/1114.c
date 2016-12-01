// Lukasavicus 1114

#include <stdio.h>


main (){
  int const password = 2002;
  int passReaded;

  do {
    scanf("%d", &passReaded);
    if(passReaded == password){
      printf("Acesso Permitido\n");
      break;
    }
    else
      printf ("Senha Invalida\n");
  } while (1);

}