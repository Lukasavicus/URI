//Lukasavicus 1149

#include <stdio.h>

main(){
  int n, a, i, sum = 0;

  scanf("%d", &a);

  do{
  	scanf("%d", &n);
  	if(n > 0)
  		break;
  }while(1);

  for(i = a+n-1; i >= a; i--)
    sum += i;

  printf ("%d\n", sum);
}