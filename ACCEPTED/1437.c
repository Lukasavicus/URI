// Lukasavicus 1437

#include <stdio.h>

main(){
	
	int n, i, pos;
	char c;

	do{
		scanf("%d", &n);
		for(i = 0, pos = 0; i < n; i++){
			scanf("\n%c", &c);
			if(c == 'D')
				pos = (pos+1) % 4;
			else if(c == 'E')
				pos = (pos+3) % 4;
		}
		if(n != 0){
			switch (pos){
				case 0: printf("N\n"); break;
				case 1: printf("L\n"); break;
				case 2: printf("S\n"); break;
				case 3: printf("O\n"); break;
			}
		}

	}while(n != 0);

}