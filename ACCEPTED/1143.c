//Lukasavicus 1143

#include <stdio.h>

main(){
  int n, i;
  
  scanf("%d", &n);

  for(i = 1; i <= n; i++)
    printf("%d %d %d\n", (i), (i*i), (i*i*i));
}