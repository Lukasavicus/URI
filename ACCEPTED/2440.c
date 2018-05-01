/**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Outras Fontes razoaveis:
 * http://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/digraphdatastructs.html#DIGRAPHlists-library
 * http://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/digraphdatastructs.html#DIGRAPHmatrix-library
 *
 */

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

#define MODO_SEM_IMPRESSAO 0
#define MODO_IMPRESSAO 1
// +++++++++++++++++++++++++++

// It need to be Not So Big cause if was really big if you add one unit you finish the cycle and the turn negative
#define BIG 214748
#define BIGGER 214748364
#define BIGGEST 2147483647

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

	void insere(){
		while(1)
			break;
	}

	int estaVazia(Grafo g);
	void inic_grafo(Grafo * g, int tam);
	void limpa_grafo(Grafo g, int tam);

	void insere_s_rep(Grafo g, int id, tipo_info nova_info);

	void insere_rep_fim(Grafo g, int id, tipo_info nova_info, int modo_repeticao, int peso);

	void libera(Vertice * n);
	void desaloca(Grafo *g, int tam);
	Grafo transpor_grafo(Grafo g,int tam);
	Grafo CFC(Grafo g, int tam, int id_root, int * id_grupo);
	int numero_de_componentes(Grafo g, int tam);


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
			(*g)[i].peso = 0;
		}
	}

	/* Limpa todas as variaveis usadas nas buscas.
	 * Entrada:
	 * 		Grafo g (variavel);
	 * 		int tam (quantidade de vertices do grafo).
	 */
	void limpa_grafo(Grafo g, int tam){
		int i;
		if(!estaVazia(g))
			for(i = 0; i < tam; i++){
				g[i].cor = BRANCO;
				g[i].predecessor = RAIZ;
				g[i].distancia = INF;
				g[i].tempo_descoberta = TZERO;
				g[i].tempo_finalizacao = TZERO;
				g[i].id_grupo = SEM_GRUPO;
				g[i].peso = 0;
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

	void insere_inicio(Grafo g, int id, tipo_info nova_info, int peso){
		Vertice * n;

		n = (Vertice *)malloc(sizeof(Vertice));
		n->info = nova_info;
		n->peso = peso;
		n->prox = NULL;

		 if(g[id].prox == NULL){
			g[id].prox = n;
		}
		else{
			n->prox = g[id].prox;
			g[id].prox = n;
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



// ======================================= COMPONENTES CONEXAS =====================================


	// Algoritmo de Tarjan - Adaptacao do material do Prof Feofiloff
	// Disponivel em: http://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/tarjan.html
	int Tarjan(Grafo g, int tam){
		//printf("Tarjan(g, tam:%d)\n", tam);
		int *pre, *low, *stack, *sc;
		int conta, k, N;
		int i;

		pre = 	(int *) malloc(tam * sizeof(int));
		low = 	(int *) malloc(tam * sizeof(int));
		stack = (int *) malloc(tam * sizeof(int));
		sc = 	(int *) malloc(tam * sizeof(int));

		for(i = 0; i < tam; i++){
			pre[i] = -1;
		}

		conta = 0; k = 0; N = 0;

		for(i = 0; i < tam; i++){
			if(pre[i] == -1)
				BEP_CC(g, tam, i, pre, low, stack, sc, &conta, &k, &N);
		}

		free(pre); free(low); free(stack);

		return k;
	}

	void BEP_CC(Grafo g, int tam, int v, int pre[], int low[], int stack[], int sc[], int *conta, int *k, int *N){ // v == id_root
		//printf("BEP_CC(v:%d)\n", v);
		Vertice *a;

		pre[v] = (*conta)++;
		low[v] = pre[v];
		stack[(*N)++] = v;

		for(a = g[v].prox; a != NULL; a = a->prox){
			tipo_info w = a->info;
			//printf("v%d [v]%d w%d [w]%d\n", v, pre[v], w, pre[w]);
			//imprime_vertice(g, v);
			if(pre[w] == -1)
				BEP_CC(g, tam, w, pre, low, stack, sc, conta, k, N);
			if(low[w] < low[v])
				low[v] = low[w];
		}
		if (low[v] < pre[v])
			return; 
		do{ 
			tipo_info u = stack[--(*N)];
			sc[u] = (*k);
			low[u] = tam;
		}while (stack[(*N)] != v); 
		(*k)++;
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// ==================================================================================================================================================

	void Test2440(){
		Grafo g;
		int m, n;
		int a, b;
		scanf("%d %d", &m, &n);

		inic_grafo(&g, m);

		while(n--){
			scanf("%d %d", &a, &b);
			insere_rep_fim(g, a-1, b-1, SEM_REP, SEM_PESO);
			insere_rep_fim(g, b-1, a-1, SEM_REP, SEM_PESO);
		}

		//int aux = numero_de_componentes(g, m );
		int aux = Tarjan(g, m);
		printf("%d\n", aux);
	}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



int main(){
	Test2440();
	return 0;
}