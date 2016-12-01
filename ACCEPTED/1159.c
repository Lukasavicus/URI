//Lukasavicus 1159

#include <stdio.h>

main(){
  int a;

  do {
    scanf ("%d", &a);

    if(a == 0)
      return;

    if(a % 2 != 0)
      a++;

    printf("%d\n", (a*5)+20);
  }while(1);

}