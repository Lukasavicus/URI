/* Lukasavicus - 1547 */

#include <stdio.h>

int main(){
	
	int TC, qt, s, aux, smaller, smaller_idx, n;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &qt, &s);
		smaller = 10000;
		smaller_idx = 0;
		for(int i = 0; i < qt; i++){
			scanf("%d", &n);
			aux = (n > s) ? (n-s) : (s-n);
			if(aux < smaller){
				smaller = aux;
				smaller_idx = i;
			}
		}
		printf("%d\n", (smaller_idx+1));
	}

	return 0;
}