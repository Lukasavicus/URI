/* Lukasavicus - 1715 */

#include<stdio.h>

int main(){
	int n, m, aux;
	int flag_row = 1, flag_total = 0;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++, flag_row = 1){
		for(int j = 0; j < m; j++){
			scanf("%d", &aux);
			if(!aux)
				flag_row = 0;
		}
		flag_total += flag_row;
	}
	printf("%d\n", flag_total);
	return 0;
}