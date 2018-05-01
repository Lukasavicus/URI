//Lukasavicus 1534

#include <stdio.h>

main(){
  int n, i, j;
  do{
	  for(i = 0; i< n; i++){
	    for(j = 0; j < n; j++){
	      if(j == (n-i-1))
	        printf("2");
	      else if(i == j)
	        printf("1");
	       else
	        printf("3");	        
	    }
	    //if(i != n-1)
	    	printf("\n");
	  }
	}while(scanf("%d", &n) != EOF );
}
