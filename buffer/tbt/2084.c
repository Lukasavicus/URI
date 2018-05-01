/* Lukasavicus 2084 */

#include <stdio.h>

int main(){

	int i, j, n, aux, c[10], sum = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &c[i]);
		sum += c[i];
	}
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if(c[i] < c[j]){
				aux = c[i];
				c[i] = c[j];
				c[j] = aux;
			}

	if((c[0] >= (0.45*sum)) || ((c[0] >= (0.4*sum)) && ((c[0] - c[1]) >= (0.1*sum))))
		printf("1\n");
	else
		printf("2\n");

	return 0;
}