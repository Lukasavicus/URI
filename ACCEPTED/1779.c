// Lukasavicus 1779

#include <stdio.h>

int main(){
	
	int TC, big, big_in_seq, seq_of_big, aux, i, n, j = 0;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &n);
		j++;
		for(i = 0, big = 0, big_in_seq = 0, seq_of_big = 0; i < n; i++){
			scanf("%d", &aux);
			if(aux > big){
				big = aux;
				seq_of_big = 1;
				big_in_seq = 1;
			}
			else if(aux == big){
				seq_of_big++;
				if(seq_of_big > big_in_seq)
					big_in_seq = seq_of_big;
			}
			else{
				seq_of_big = 0;
			}
		}
		printf("Caso #%d: %d\n", j, big_in_seq);
	}

	return 0;
}