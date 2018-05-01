//Lukasavicus 1150


#include <stdio.h>

main(){
  int x, z, i, pass = 0;

  scanf("%d", &x);

  do{
  	scanf("%d", &z);
  	if(z > x)
  		break;
  }while(1);

  for(pass += x, i = 1; pass <= z; x++, pass+= x, i++);
  
  printf("%d\n", i);

}