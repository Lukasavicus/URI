// Lukasavicus 1901

#include <stdio.h>

#define MAXN 200
#define MAXF 1000

int main(){
	int founded[MAXF];
	int m[MAXN][MAXN];

	int n, qnt_diff = 0, i, j, pi, pj, f;

	for(i = 0; i < MAXF; i++)
		founded[i] = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &m[i][j]);
		}
	}

	n *= 2;

	for(i = 0; i < n; i++){
		scanf("%d %d", &pi, &pj);
		f = m[pi-1][pj-1];
		founded[f-1]++;
	}

	for(i = 0, qnt_diff = 0; i < MAXF; i++)
		if(founded[i])
			qnt_diff++;

	printf("%d\n", qnt_diff);

	return 0;
}