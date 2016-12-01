// Lukasavicus 1875

#include <stdio.h>

void main(){
	int n , i, j, m, pr, pg, pb;
	char orig, dest;
	
	char buffer[100];
	
	scanf("%d\n", &n);
	
	for(i = 0; i < n; i++){
		
		scanf("%d", &m);

		for(j = 0, pr = 0, pg = 0, pb = 0; j < m; j++){
						
			//scanf("\n");

			scanf("\n%c %c", &orig, &dest);
			//printf(">%c<>%c<\n", orig, dest);
			
			if(orig == 'R'){
				if(dest == 'G')
					pr += 2;
				else if(dest == 'B')
					pr++;
			}
			else if(orig == 'G'){
				if(dest == 'B')
					pg += 2;
				else if(dest == 'R')
					pg++;
			}
			else if(orig == 'B'){
				if(dest == 'R')
					pb += 2;
				else if(dest == 'G')
					pb++;
			}
			//printf("%d %d %d\n", pr, pg, pb);
		}
		if(pr == pg && pg == pb)
			printf("trempate\n");
		else if(pr > pg && pr > pb)
			printf("red\n");
		else if(pg > pr && pg > pb)
			printf("green\n");
		else if(pb > pr && pb > pg)
			printf("blue\n");
		else if(pr == pg || pr == pb || pg == pb)
			printf("empate\n");
	}
	
}
