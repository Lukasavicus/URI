//Lukasavicus 1914

#include <stdio.h>
#include <string.h>

main(){
	
  char name1[101], name2[101], c1[6], c2[6];
  int n, i;
  long long int a, b;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
  	//printf("%d\n", n);
	scanf("%s %s %s %s %lld %lld", name1, c1, name2, c2, &a, &b);
	//printf("%s %s %s %s %lld %lld\n", name1, c1, name2, c2, a, b);
  	if((a+b) % 2 == 0){
  		if(strcmp("PAR", c1) == 0)
  			printf("%s\n", name1);
  		else
  			printf("%s\n", name2);
	}
	else{
		if(strcmp("IMPAR", c1) == 0)
  			printf("%s\n", name1);
  		else
  			printf("%s\n", name2);
	}
  }
  
}
