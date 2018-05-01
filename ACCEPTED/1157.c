//Lukasavicus 1157

#include <stdio.h>

main(){
  int n, i, TAM;

  scanf("%d", &n);
  TAM = n /2;

  for(i = 1; i <= TAM; i++)
    if(n % i == 0)
      printf("%d\n", i);

  printf("%d\n", n);

}