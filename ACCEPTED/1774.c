/* Lukasavicus - 1774 */

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

// ===== OPCOES - INSERE =====
#define INICIO 		0
#define FIM 		1

#define COM_REP 	0
#define SEM_REP 	1

#define SEM_PESO	0
#define COM_PESO	1
// +++++++++++++++++++++++++++

#define BIG 2147483647

// ==== ESTRUTURAS E TIPOS ===
typedef int tipo_info;
typedef int info_peso;

typedef struct _vertice{
	tipo_info info;
	info_peso peso;
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
	info_peso peso;
}Lista_adj;

//typedef int ** Matriz_Inc;
//typedef int ** Matriz_Adj;

typedef Lista_adj * Grafo;
// +++++++++++++++++++++++++++

// =========================================== Cabecalhos ==========================================

	int estaVazia(Grafo g);
	void inic_grafo(Grafo * g, int tam);
	void limpa_grafo(Grafo g, int tam);

	void insere_rep_fim(Grafo g, int id, tipo_info nova_info, int modo_repeticao, int peso);

	void imprime_grafo(Grafo g, int tam, int modo_peso);
	void imprime_lista_adjacencias(Grafo g, int tam);
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
			(*g)[i].peso = 0;
		}
	}


	/* Insere um vertice com nova_info na lista de adjacencia do vertice identificado por id.
	 * Entrada:
	 * 		Grafo g;
	 * 		int nova_info;
	 * 		int id;
	 */
	void insere_rep_fim(Grafo g, int id, tipo_info nova_info, int modo_repeticao, int peso){
		Vertice * n;

		n = (Vertice *)malloc(sizeof(Vertice));
		n->info = nova_info;
		n->peso = peso;
		n->prox = NULL;

		Vertice * p;

		p = g[id].prox;

		if(estaVazia(g)){
			printf("Erro\n");
		}
		else if(p == NULL){
			//printf("Vazio\n");
			g[id].prox = n;
		}
		else{
			if(modo_repeticao && p->info == nova_info) return;
			while(p->prox != NULL){
				//printf(">%d< ", p->info);
				if(modo_repeticao && p->info == nova_info) return;
				p = p->prox;
			}
			if(modo_repeticao && p->info == nova_info) return;
			p->prox = n;
			//printf("\n");
		}
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// ===================================== ARVORE GERADORA MINIMA ====================================
	int peso_da_aresta(Grafo g, int id_v_a, int id_v_b){
		Vertice * v;

		v = g[id_v_a].prox;
		//printf("> ");
		while(v != NULL){
			//printf("%d ", v->info);
			if(v->info == id_v_b){
				return v->peso;
			}
			v = v->prox;
		}
		return -1;
	}

	int Prim(Grafo g, int tam, int id_root){
		int W = 0;
		int i, min, i_min;

		int peso_aresta;

		int * listaQ;
		int Qsize = tam;

		int * peso;

		Vertice * v;

		peso = (int *) malloc(tam * sizeof(int));
		listaQ = (int *) malloc(tam * sizeof(int));

		for(i = 0; i < tam; i++){
			peso[i] = BIG;
			listaQ[i] = 1;
		}
		peso[id_root] = 0;
		g[id_root].predecessor = id_root;

		while(Qsize--){
			min = BIG;
			i_min = -1;

			//printf("TAM: %d\n", tam);

			//for(i = 0; i < tam; i++)	printf("I:%d\tQ:%d\tP:%d\t- %d[%d] :%d:\n", i, listaQ[i], peso[i], min, i_min, Qsize);

			for(i = 0; i < tam; i++){
				if(listaQ[i] && peso[i] < min){
					min = peso[i];
					i_min = i;
				}
			}

			listaQ[i_min] = 0;
			//printf("%d\n", i_min);

			W += min;
			v = g[i_min].prox;
			//printf("Adj[%d]: ", i_min);
			while(v != NULL){
				//printf("%d ", v->info);
				peso_aresta = peso_da_aresta(g, i_min, v->info);
				//printf("w:[%d][%d] : %d\n", i_min, v->info, peso_aresta);
				if(listaQ[v->info] && peso[v->info] > peso_aresta){
					peso[v->info] = peso_aresta;
					g[v->info].predecessor = i_min;
				}
				v = v->prox;
			}
			//printf("\n");
		}
		return W;
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// =========================================== Impressoes ==========================================
	/* Imprime a lista de adjacencia de todos os vertices.
	 * 		Grafo g (variavel);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void imprime_grafo(Grafo g, int tam, int modo_peso){
		int i;

		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				printf("I[%d]: ",  i);
				while(p != NULL){
					if(modo_peso)
						printf("[%d]", p->peso);
					printf("%d ",  p->info);
					p = p->prox;
				}
				printf("\n");
			}
		}	
	}


	/* Imprime a lista de adjacencia de todos os vertices.
	 * 		Grafo g (variavel);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void imprime_lista_adjacencias(Grafo g, int tam){
		int i;

		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				printf("I[%d]\td:%d\tp:%d\ttd:%d\ttf:%d\tig:%d\tp:%d\n",  i, g[i].distancia, g[i].predecessor, g[i].tempo_descoberta, g[i].tempo_finalizacao, g[i].id_grupo, g[i].peso);
			}
		}	
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void main(){
	int n, m, a, b, c, i;
	int result;
	Grafo g;

	scanf("%d %d", &n, &m);
	inic_grafo(&g, n);
	for(i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		insere_rep_fim(g, a-1, b-1, SEM_REP, c);
		insere_rep_fim(g, b-1, a-1, SEM_REP, c);
	}
	/*
	imprime_grafo(g, n, COM_PESO);
	imprime_lista_adjacencias(g, n);
	*/
	result = Prim(g, n, 0);
	printf("%d\n", result);
}