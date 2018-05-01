//Lukasavicus 1145

#include <stdio.h>
    
main(){
      int i, br, max;
    
      scanf("%d %d", &br, &max);
    
	for(i = 1; i <= max; i++){
    	printf("%d", i);
        	
    	if(i % br == 0)
    		printf ("\n");
    	else
    		printf(" ");
    }
}