//Lukasavicus 1132

#include <stdio.h>

main(){
  int n1, n2, i, sum = 0;
  scanf ("%d %d", &n1, &n2);

  int aux;

  if(n2 < n1){
  	aux = n1;
  	n1 = n2;
  	n2 = aux;
  }

  for(i = n1; i <= n2; i++){
  	//printf("%d ", i );
    if(i % 13 != 0)
      sum+= i;
  }
      
  printf("%d\n", sum);
}