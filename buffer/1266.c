/* Lukasavicus - 1266 */

#include <stdio.h>

#define MAX 5001
#define BIG 999

int absdiff(const int a, const int b){
	return (a > b) ? (a - b) : (b - a);
}

int main(){

	int n, postes[MAX], min, i, aux;
	int idx_left, idx_rigth, flag;

	const int debug = 0;
	
	while(1){
		scanf("%d", &n);

		if(n == 0)
			break;
			
		min = BIG;
		for(i = 0; i < n; i++)
			scanf("%d", &postes[i]);
			
		if(debug){
			for(i = 0; i < n; i++){
				printf("[%d]%d\n", i, postes[i]);
			}
		}

		idx_left = 0;
		idx_rigth = 0;
		flag = 0;
		for(i = 0; i < n; i++){
			if(postes[i] == 0){

				if(i > 0)
					idx_left = i - 1;
				if(i < n)
					idx_rigth = i + 1;
					
				while(idx_left > 0 && postes[idx_left] != 1 ){
					idx_left--;
				}

				while(idx_rigth < n && postes[idx_rigth] != 1){
					idx_rigth++;
				}
				
				i = idx_rigth;

				if(debug) printf("%d %d %d %d\n", idx_left, idx_rigth, i, postes[i]);

				aux = absdiff(idx_left, idx_rigth)-1;

				if(aux > 1 && aux < min && postes[idx_left] == 1 && postes[idx_rigth] == 1)
					min = aux;
			}
		}
		printf("%d\n", min);
	}

	return 0;
}

/*

if(i == 1)
				idx_one_plus = i;
			else
				idx_zero = i;
			
			aux = absdiff(idx_one, idx_one_plus);
			if(idx_one != -1 && idx_one_plus != -1 && aux > 1 && aux < min)
				min = aux;

*/