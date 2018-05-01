//Lukasavicus 1142

#include <stdio.h>

main(){
  int n, i;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    printf("%d %d %d PUM\n", (i*4+1), (i*4+2), (i*4+3));

}