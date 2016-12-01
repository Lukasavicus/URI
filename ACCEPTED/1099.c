// Lukasavicus 1099

#include <stdio.h>

main (){

  int n1, n2, aux, sum, i, qnt, j;

  scanf("%d", &qnt);


  for(j = 0; j < qnt; j++){
	  scanf("%d %d", &n1, &n2);

	  if (n1 > n2){
	    aux = n1;
	    n1 = n2;
	    n2 = aux;
	  }

	  n1++;

	  if(n1 % 2 == 0)
	    n1++;

	  for (i = n1, sum = 0; i < n2; i+= 2)
	    sum += i;

	  printf ("%d\n", sum); //n1, n2
  }

}