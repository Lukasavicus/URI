// Lukasavicus 1023

#include <stdio.h>

#define MAX 200

typedef struct _casa{
	int p; //pessoas
	int c; //consumo
}Casa;

int main(){
	
	Casa v[MAX];
	int i, k, n, qnt_pes, cons, c_total, p_total, auxi;
	long double aux;

	int flag = 0;


	k = 0;
	while(1){
		k++;
		scanf("%d", &n);
		if(!n)
			return 0;
		if(flag){
			printf("\n");
		}
		flag = 1;

		for(i = 0; i < MAX; i++){
			v[i].p = 0;
			v[i].c = 0;
		}

		for(i = 0, c_total = 0, p_total = 0; i < n; i++){
			scanf("%d %d", &qnt_pes, &cons);
			v[(cons/qnt_pes)].p += qnt_pes;
			v[(cons/qnt_pes)].c = (cons/qnt_pes);
			p_total += qnt_pes;
			c_total += cons;
		}

		printf("Cidade# %d:\n", k);

		for(i = 0, auxi = p_total; i < MAX; i++){
			if(!(v[i].p == 0 && v[i].c == 0)){
				printf("%d-%d", v[i].p, v[i].c);
				auxi -= v[i].p;
				if(auxi != 0)
					printf(" ");
			}
		}
		aux = ((long double)(c_total) / (long double)(p_total));
		aux *= 10;
		aux *= 10;
		auxi = (int)(aux)/1;
		aux = auxi / 100.00;
		printf("\nConsumo medio: %.2LF m3.\n", aux);

	}

	return 0;
}