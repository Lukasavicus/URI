/* Lukasavicus - 1125 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 101

typedef struct _pontuacao{
	int id;
	int total;
}Pontuacao;

int resultados[MAX][MAX];
Pontuacao placar[MAX];
int n_sistemas[MAX];
int sistema[MAX][MAX];

void zeraPontos(int n){
	int i;
	for(i = 0; i < n; i++){
		placar[i].id = i+1;
		placar[i].total = 0;
	}
}

int compare(const void *a, const void *b){

	Pontuacao *pa = (Pontuacao *)a;
	Pontuacao *pb = (Pontuacao *)b;
	
	if(pa->total < pb->total)
		return 1;
	else if(pa->total > pb->total)
		return -1;
	else{
		return pa->id - pb->id;
	}
}

void init(){
	int i, j;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			resultados[i][j] = -1;
		}
	}
}

int printClassificacao(int P){
	int i = 0;
	int max = placar[0].total;
	printf("%d", placar[i].id);
	for(i = 1; i < P; i++){
		if(placar[i].total == max)
			printf(" %d", placar[i].id);
	}
	printf("\n");
}


int main(){

	init();
	zeraPontos(MAX);

	const int DEBUG = 0;

	int i, j, k, l;	
	int aux_idx, aux;
	int G, P, S, n_sis;
	
	while(1){
		scanf("%d %d", &G, &P);

		if(G == 0 && P == 0)
			break;
		// =================================================
			for(j = 0; j < G; j++){
				for(i = 0; i < P; i++){
					scanf("%d", &aux);
					resultados[i][j] = aux - 1;
				}
			}
		// +++++++++++++++++++++++++++++++++++++++++++++++++
		if(DEBUG){
			printf("=================================================\n");
			for(j = 0; j < G; j++){
				for(i = 0; i < P; i++){
					aux = resultados[i][j] + 1;
					printf("%d ", aux);
				}
				printf("\n");
			}
			printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
		}
		
		scanf("%d", &S);
		
		// =================================================
			for(i = 0; i < S; i++){
				scanf("%d", &aux);
				n_sistemas[i] = aux;
				for(j = 0; j < aux; j++){
					scanf("%d", &sistema[i][j]);
				}
			}
		// +++++++++++++++++++++++++++++++++++++++++++++++++
		if(DEBUG){
			for(i = 0; i < S; i++){
				for(j = 0; j < n_sistemas[i]; j++){
					printf("%d ", sistema[i][j]);
				}
				printf("\n");
			}
		}

		if(DEBUG) printf(">%d %d %d<\n", S, P, G);

		for(i = 0; i < S; i++){
			for(l = 0; l < G; l++){
				for(k = 0; k < P; k++){
					aux_idx = resultados[k][l];
					if(DEBUG) printf("[%d][%d]: %d ", k, l, resultados[k][l]);
					if(aux_idx < n_sistemas[i]){
						if(DEBUG) printf("[%d][%d]: %d\n",  i, k, sistema[i][aux_idx]);
						placar[k].total += sistema[i][aux_idx];
					}
					if(DEBUG) printf("\n");
				}
			}

			if(DEBUG){
				for(k = 0; k < P; k++)
					printf("%d:[%d]%d ", k, placar[k].id, placar[k].total);
				printf("\n");
			}

			qsort(placar, P, sizeof(Pontuacao), compare);	

			if(DEBUG){
				for(k = 0; k < P; k++)
					printf("%d:[%d]%d ", k, placar[k].id, placar[k].total);
				printf("\n");
			}

			printClassificacao(P);
			zeraPontos(P);
		}

	}		
}	
