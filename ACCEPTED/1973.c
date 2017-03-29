// Lukasavicus 1973

#include <stdio.h>

#define MAX 1123456

typedef long long int lli;

int mem[MAX];
int atk[MAX];

int main(){

	lli sum = 0, roubo = 0;
	int TC, max = -1, i, estrelas, aux;

	for(i = 0; i < MAX; i++)
		atk[i] = 0;

	scanf("%d", &TC);
	
	for(i = 0; i < TC; i++){
		scanf("%d", &mem[i]);
		sum += mem[i];
	}

	i = 0;
	while(1){
		//printf(">[%d]:%d\n", i, mem[i]); int j; 	for(j = 0; j < TC; j++) printf("%d ", mem[j]); printf("\n");

		aux = mem[i];

		if(i < 0 || i >= TC)
			break;

		if(mem[i]){
			mem[i]--;
			roubo++;
			atk[i] = 1;
		}

		if(aux%2) 	i++;
		else		i--;

	}

	for(i = 0, estrelas = 0; i < MAX; i++)
		estrelas += atk[i];

	printf("%d %lld\n", estrelas, (sum - roubo));

	return 0;
}