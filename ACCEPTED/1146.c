//Lukasavicus 1146

#include <stdio.h>

main(){
  
  int i, n;

  do{
    scanf("%d", &n);
    if(n == 0)
      return;

    for (i = 1; i <= n; i++){
      printf ("%d", i);
      if(i < n)
      	printf (" ");
    }
    printf ("\n");
  } while (1);

}