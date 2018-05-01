/* Lukasavicus - 1205 */

// Precisa de uma heap estatica para implementar uma lista de prioridades para as distâncias do Dijkstra;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

typedef struct _no{
	tipo_info info;
	struct _no *prox;
}No;

typedef struct _heap{
	int id;
	int info;
}Heap;

typedef No * Lista;

//typedef int ** Matriz_Inc;
//typedef int ** Matriz_Adj;

typedef Lista_adj * Grafo;
// +++++++++++++++++++++++++++

// =========================================== Cabecalhos ==========================================

	int estaVazia(Grafo g);
	void inic_grafo(Grafo * g, int tam);
	void limpa_grafo(Grafo g, int tam);

	void insere_rep_fim(Grafo g, int id, tipo_info nova_info, int modo_repeticao, int peso);

	void libera(Vertice * n);
	void desaloca(Grafo *g, int tam);

	void imprime_grafo(Grafo g, int tam, int modo_peso);
	void imprime_caminho_raiz_vertice_v2(Grafo g, int id_root);
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
		int i;
		Vertice * p;
		for(i = 0; i < tam; i++){
			//printf("%d: ", (*g)[i].info);
			libera((*g)[i].prox);
			//printf("\n");
		}
		free(*g);
		*g = NULL;
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// ============================================= Lista =============================================
	void lista_inic_lista(Lista *l){
		*l = NULL;
	}

	/* Insere um elemento na lista de maneira ordenada.
    Caso a lista nao esteja ordenada, ordena antes da insercao */
	void lista_insere_ordenado_iter(Lista *l, tipo_info nova_info){
		No * n;

		n = (No *) malloc (sizeof(No));
		n->info = nova_info;
		n->prox = NULL;

		Lista p = *l;

		if(*l == NULL){
			*l = n;
		}
		else if(*l != NULL && (*l)->info > nova_info){
			n->prox = *l;
			*l = n;
		}
		else{
			while(p->prox != NULL && p->prox->info < nova_info)
				p = p->prox;

			n->prox = p->prox;
			p->prox = n;

		}
	}

	/* Remove o elemento que esta no inicio da lista.
	    Retorna 0 caso a lista esteja vazia */
		tipo_info lista_exclui_inicio(Lista *l){
			Lista p;
			tipo_info info;

			if(*l == NULL) // Tem 0 elemento
				return -1;
			else{ // Tem 1 ou + elemento(s)
				info = (*l)->info;
				p = (*l)->prox;
				free(*l);
				*l = p;
				return info;
			}
		}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// =================================== ARVORE DE CAMINHOS MINIMOS ==================================
	int Dijsktra_VerticesPonderados(Grafo g, int tam, int id_root, int id_end){
		int i, min, i_min;

		int peso_vertice;

		int * listaS;
		int Ssize = tam;

		int * dist;

		Vertice * v;

		dist = (int *) malloc(tam * sizeof(int));
		listaS = (int *) malloc(tam * sizeof(int));

		for(i = 0; i < tam; i++){
			dist[i] = BIG;
			listaS[i] = 1;
		}
		dist[id_root] = g[id_root].peso;
		g[id_root].predecessor = id_root;

		while(Ssize--){
			min = BIG;
			i_min = -1;

			//printf("TAM: %d\n", tam);

			//for(i = 0; i < tam; i++)	printf("I:%d\tQ:%d\tP:%d\t- %d[%d] :%d:\n", i, listaS[i], dist[i], min, i_min, Ssize);

			for(i = 0; i < tam; i++){
				if(listaS[i] && dist[i] < min){
					min = dist[i];
					i_min = i;
				}
			}

			listaS[i_min] = 0;
			//printf("%d\n", i_min);

			v = g[i_min].prox;
			//printf("Adj[%d]: ", i_min);
			while(v != NULL){
				//printf("%d ", v->info);
				peso_vertice = dist[i_min] + g[v->info].peso;//peso_da_aresta(g, i_min, v->info) + dist[i_min];
				//printf("w:[%d][%d] : %d\n", i_min, v->info, peso_vertice);
				if(listaS[v->info] && dist[v->info] > peso_vertice){
					dist[v->info] = peso_vertice;
					g[v->info].predecessor = i_min;
				}
				v = v->prox;
			}
			//printf("\n");
		}
		//for(i = 0; i < tam; i++)	printf("%d: %d %d\n", i, dist[i], g[i].predecessor);
		return dist[id_end];
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

	void imprime_caminho_raiz_vertice_v2(Grafo g, int id_root){
		if(g[id_root].predecessor != id_root)
			imprime_caminho_raiz_vertice_v2(g, g[id_root].predecessor);

		printf("%d\n", id_root);
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void main(){
	int n, m, k;
	double p;
	int i;
	int a, b, aux;
	int sniper;
	int st, end;
	int result;
	double final = 0.00;

	Grafo g;

	while(scanf("%d %d %d %lf", &n, &m, &k, &p) != EOF){
		inic_grafo(&g, n);
		for(i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			insere_rep_fim(g, a-1, b-1, SEM_REP, SEM_PESO);
			insere_rep_fim(g, b-1, a-1, SEM_REP, SEM_PESO);
		}
		scanf("%d", &sniper);
		for(i = 0; i < sniper; i++){
			scanf("%d", &aux);
			g[aux-1].peso++;
		}
		scanf("%d %d", &st, &end);
		//imprime_grafo(g, n, SEM_PESO);

		result = Dijsktra_VerticesPonderados(g, n, st-1, end-1);

		if(result < k)
			final = pow(p, result);

		printf("%.3lf\n", final);
		//desaloca(&g, n);

		//imprime_caminho_raiz_vertice_v2(g, end-1);

	}
}