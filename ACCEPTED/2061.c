//Lukasavicus 2061

#include <stdio.h>

main(){
  
  char action[8];

  int n, m, i;

  scanf("%d %d", &n ,&m);

  for(i = 0; i < m; i++){
  	scanf("%s", action);
  	if(action[0] == 'c')
  		n--;
  	if(action[0] == 'f')
  		n++;
  }


  printf("%d\n", n);

}