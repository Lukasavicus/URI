//Lukasavicus 1943

#include <stdio.h>

main(){
  int n;
  scanf ("%d", &n);
  printf("Top ");

  if(n <= 1)
    printf("1");
  else if(n <= 3)
    printf("3");
  else if(n <= 5)
    printf("5");
  else if(n <= 10)
    printf("10");
  else if(n <= 25)
    printf("25");
  else if(n <= 50)
    printf("50");
  else if(n <= 100)
    printf("100");
    printf("\n");
}