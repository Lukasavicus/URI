//Lukasavicus 2163

#include <stdio.h>

int main(){

	int mtx[1001][1001], i, j, n, m, x = 0, y = 0;

	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &mtx[i][j]);
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if((mtx[i][j] == 42) &&											//42
			   ((i-1 >= 0) && (i+1 <= n) && (j-1 >= 0) && (j+1 <= m)) && 	// Checks
			   ((mtx[i-1][j] == 7)   && (mtx[i+1][j] == 7))   &&			// S / N
			   ((mtx[i][j-1] == 7)   && (mtx[i][j+1] == 7))   &&			// O / L
			   ((mtx[i-1][j-1] == 7) && (mtx[i-1][j+1] == 7)) &&			// SO/SL
			   ((mtx[i+1][j-1] == 7) && (mtx[i+1][j+1] == 7))				// NO/NE
			){
				x = i;
				y = j;
			}
		}
	}


	if(x == y && y == 0)
		printf("0 0\n");
	else	
		printf("%d %d\n", x+1, y+1);

    return 0;
}