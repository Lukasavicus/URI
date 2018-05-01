// Lukasavicus 1128
/**/

#include <stdio.h>
#include <stdlib.h>

// ========= CORES ===========
#define BRANCO 0
#define CINZA 1
#define PRETO 2
// +++++++++++++++++++++++++++

// ========== INFOS ==========
#define INF -1 			// DISTANCIAS
#define RAIZ -1 		// PREDECESSORES
#define TZERO -1 		// TEMPOS
#define SEM_GRUPO -1 	// GRUPOS
// +++++++++++++++++++++++++++

// ==== ESTRUTURAS E TIPOS ===
typedef int tipo_info;

typedef struct _vertice{
	tipo_info info;
	struct _vertice *prox;
}Vertice;

typedef struct _lista_adj{
	tipo_info info;
	int cor; // Assumindo os possiveis valores: BRANCO, CINZA, PRETO;
	int predecessor; //Utiliza um id de que tipo?
	int distancia;
	int tempo_descoberta;
	int tempo_finalizacao;
	Vertice *prox;
	int id_grupo;
}Lista_adj;

//typedef int ** Matriz_Inc;
//typedef int ** Matriz_Adj;

typedef Lista_adj * Grafo;
// +++++++++++++++++++++++++++


#define MAX_VERTICES 2001
#define MAX_ARESTAS 2001000

// =========================================== Cabecalhos ==========================================
	int estaVazia(Grafo g);
	void inic_grafo(Grafo * g, int tam);
	void limpa_grafo(Grafo g, int tam);
	void insere(Grafo g, int id, tipo_info nova_info);
	void libera(Vertice * n);
	void desaloca(Grafo *g, int tam);

	Grafo transpor_grafo(Grafo g,int tam);
	int Kosaraju_Sharir(Grafo g, int tam);

	void BEP_AUX(Grafo g, int id_root, int modo, int * tempo, int id_grupo);
	void ALL_BEP(Grafo g, int tam, int id_root, int modo, int * tempo);

	int Tarjan(Grafo g, int tam);
	void BEP_CC(Grafo g, int tam, int v, int pre[], int low[], int stack[], int sc[], int *conta, int *k, int *N);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ========================================= Funcoes Uteis =========================================
	
	/* Verifica se um grafo esta vazio.
	 * Entrada:
	 * 		Grafo g (variavel, nao ponteiro);
	 * Saida:
	 * 		1 - Vazio;
	 * 		0 - C.C.;
	 */
	int estaVazia(Grafo g){
		return g == NULL;
	}

	/* Inicia o Grafo alocando espaco para 'tam' posicoes.
	 * Entrada:
	 *		Grafo *g (ponteiro, para poder apontar para o novo espaco alocado);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void inic_grafo(Grafo * g, int tam){
		int i;

		*g = (Lista_adj *)malloc(tam * sizeof(Lista_adj));

		for(i = 0; i < tam; i++){
			(*g)[i].info = i;
			(*g)[i].cor = BRANCO;
			(*g)[i].predecessor = RAIZ;
			(*g)[i].distancia = INF;
			(*g)[i].tempo_descoberta = TZERO;
			(*g)[i].tempo_finalizacao = TZERO;
			(*g)[i].prox = NULL;
			(*g)[i].id_grupo = SEM_GRUPO;
		}
	}


	/* Insere um vertice com nova_info na lista de adjacencia do vertice identificado por id.
	 * Entrada:
	 * 		Grafo g;
	 * 		int nova_info;
	 * 		int id;
	 */
	void insere(Grafo g, int id, tipo_info nova_info){
		Vertice * n;

		n = (Vertice *)malloc(sizeof(Vertice));
		n->info = nova_info;
		n->prox = NULL;

		//Vertice * p;

		//p = g[id].prox;

		 if(g[id].prox == NULL){
			//printf("Vazio\n");
			g[id].prox = n;
		}
		else{
			n->prox = g[id].prox;
			g[id].prox = n;
			//while(p->prox != NULL){
				//printf(">%d< ", p->info);
			//	p = p->prox;
			//}
			//p->prox = n;
		}
	}

	/* (Funcao Auxiliar) Remove recursivamente todos os elementos de uma lista ligada (do ultimo para o primeiro)
	 * Entrada:
	 * 		Vertice * n (Ponteiro que aponta para o primeiro elemento da lista ligada).
	 */
	void libera(Vertice * n){
		if(n != NULL){
			//printf("%d, ", n->info);
			if(n->prox != NULL)
				libera(n->prox);

			if(n->prox == NULL){
				free(n);
				n = NULL;
			}
		}
	}

	/* Desaloca o espaco usado para o vetor da lista de adjacencias que representa um grafo.
	 * Entrada:
	 *		Grafo *g (ponteiro, para poder liberar (free) o espaco alocado);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void desaloca(Grafo *g, int tam){
		//int i;
		//Vertice * p;
		//for(i = 0; i < tam; i++){
			//printf("%d: ", (*g)[i].info);
		//	libera((*g)[i].prox);
			//printf("\n");
		//}
		free(*g);
		*g = NULL;
	}

	Grafo transpor_grafo(Grafo g,int tam){
		Grafo gt;
		inic_grafo(&gt, tam);
		int i;

		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				while(p != NULL){
					insere(gt, p->info, i);
					p = p->prox;
				}
			}
		}	
		return gt;
	}

	void imprime_lista_adjacencias(Grafo g, int tam){
		int i;

		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				printf("I[%d]\td:%d\tp:%d\ttd:%d\ttf:%d\tig:%d\n",  i, g[i].distancia, g[i].predecessor, g[i].tempo_descoberta, g[i].tempo_finalizacao, g[i].id_grupo);
			}
		}	
	}

	void imprime_grafo(Grafo g, int tam){
		int i;

		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				printf("I[%d]: ",  i);
				while(p != NULL){
					printf("%d ",  p->info);
					p = p->prox;
				}
				printf("\n");
			}
		}	
	}

	int Kosaraju_Sharir(Grafo g, int tam){
		Grafo gt;
		
		int i, j, k;

		//imprime_grafo(g, tam);

		int tempo = 0;

		int max = -1, imax = 0;

		gt = transpor_grafo(g, tam);

		ALL_BEP(g, tam, 0, 0, &tempo);

		//imprime_lista_adjacencias(g, tam);
		//printf("\n");

		tempo = 0;

		for(j = 0, max = -1, imax = -1; j < tam; j++){
			//printf("[%d] %d == %d && %d > %d\n", j, gt[j].tempo_descoberta, TZERO, g[j].tempo_finalizacao, max);
			if(gt[j].tempo_descoberta == TZERO && g[j].tempo_finalizacao > max){
				max = g[j].tempo_finalizacao;
				imax = j;
			}
		}
		//printf(">>%d %d\n", max, imax);
		//printf("Lista1:\n"); imprime_lista_adjacencias(gt, tam); printf("\n");
		if(imax != -1){
			BEP_AUX(gt, imax, 0, &tempo, 0);
		}

		//imprime_lista_adjacencias(gt, tam);

		for(i = 0; i < tam; i++){
			if(gt[i].id_grupo != 0)
				return 0;
		}

		//printf("Lista3:\n");
		

		return 1;
	}

	void BEP_AUX(Grafo g, int id_root, int modo, int * tempo, int id_grupo){

		g[id_root].cor = CINZA;
		g[id_root].id_grupo = id_grupo;
		g[id_root].tempo_descoberta = *tempo;
		(*tempo) = (*tempo) + 1;

		Vertice * p;
		p = g[id_root].prox;

		while(p != NULL){
			int aux = p->info;
			if(g[aux].cor == BRANCO){


				g[aux].predecessor = id_root;
				BEP_AUX(g, aux, modo, tempo, id_grupo);
			}
			p = p->prox;
		}

		g[id_root].cor = PRETO;
		g[id_root].tempo_finalizacao = *tempo;
		(*tempo) = (*tempo) + 1;
	}

	void ALL_BEP(Grafo g, int tam, int id_root, int modo, int * tempo){
		int i;

		if(g[id_root].cor == BRANCO)
			BEP_AUX(g, id_root, modo, tempo, 0);

		for(i = 0; i < tam; i++)
			if(g[i].cor == BRANCO)
				BEP_AUX(g, i, modo, tempo, 0);
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void main(){
	int n, m;
	int a, b, d;

	int i, aux;

	Grafo g;

	do{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			break;

		inic_grafo(&g, n);

		for(i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &d);
			insere(g, a-1, b-1);
			if(d == 2)
				insere(g, b-1, a-1);
		}
		//aux = numero_de_componentes(g, n);
		aux = Kosaraju_Sharir(g, n);
		//printf(">>>>%d\n", aux);
		if(aux == 1)
			printf("1\n");
		else
			printf("0\n");
		desaloca(&g, n);
	}while(1);
}