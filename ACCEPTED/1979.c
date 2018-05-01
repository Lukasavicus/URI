/**/

#include <stdio.h>
#include <stdlib.h>

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

// =========================================== Cabecalhos ==========================================
	int estaVazia(Grafo g);
	void inic_grafo(Grafo * g, int tam);
	void limpa_grafo(Grafo g, int tam);
	void insere(Grafo g, int id, tipo_info nova_info);
	void libera(Vertice * n);
	void desaloca(Grafo *g, int tam);

	int BEP_IMPAR(Grafo g, int tam);
	int BEP_IMPAR_AUX(Grafo g, int id_root, int *coloracao, int ncor);
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
			}
	}

	/* Insere um vertice com nova_info na lista de adjacencia do vertice identificado por id.
	 * Entrada:
	 * 		Grafo g;
	 * 		int nova_info;
	 * 		int id;
	 */
	void insere_s_rep(Grafo g, int id, tipo_info nova_info){
		Vertice * n;

		n = (Vertice *)malloc(sizeof(Vertice));
		n->info = nova_info;
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
			if(p->info == nova_info) return;
			while(p->prox != NULL){
				//printf(">%d< ", p->info);
				if(p->info == nova_info) return;
				p = p->prox;
			}
			if(p->info == nova_info) return;
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



// ============================================== Buscas ===========================================

	
	int BEP_IMPAR(Grafo g, int tam){
		int *coloracao;
		int i;

		int j;

		coloracao = (int *) malloc(tam * sizeof(int));
		int ncor = 0;
		for(i = 0; i < tam; i++){
			coloracao[i] = -1;
		}

		for(i = 0; i < tam; i++){
			if(g[i].cor == BRANCO){
				if(BEP_IMPAR_AUX(g, i, coloracao, ncor)){
					//imprime_grafo(g, tam);
					//for(j = 0; j < tam; ++j)	printf("c[%d]:%d ", j, coloracao[j]);	printf("\n");
					return 1;
				}
			}
		}

		//imprime_grafo(g, tam);
		//for(j = 0; j < tam; ++j)	printf("c[%d]:%d ", j, coloracao[j]);	printf("\n");
		return 0;

	}

	int BEP_IMPAR_AUX(Grafo g, int id_root, int *coloracao, int ncor){
		//printf("Visiting: %d\n", g[id_root].info);
		g[id_root].cor = CINZA;
		coloracao[id_root] = ncor;

		Vertice * p;
		p = g[id_root].prox;
		int flag = 0;
		int retorno = 0;

		while(p != NULL){
			int aux = p->info;
			if(g[aux].cor == BRANCO){
				//printf("To visit: %d\n", aux);
				retorno = BEP_IMPAR_AUX(g, aux, coloracao, !ncor);
			}
			if(retorno){
				//printf("Retorno 1\n");
				return 1;
			}
			if((g[aux].cor == PRETO || g[aux].cor == CINZA) && (coloracao[aux] == coloracao[id_root])){
				//printf("Ciclo\n");
				return 1;
			}
			p = p->prox;
		}

		//printf("Visited: %d\n", g[id_root].info);
		g[id_root].cor = PRETO;
		return 0;
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void le_amigos(Grafo g, int pos){
	char c = ' ';
	int i = 0, vertice = 0;
	//printf("le_amigos_{\n");
	while(c == ' '){
		scanf("%d%c", &vertice, &c);
		insere_s_rep(g, pos-1, vertice-1);
		insere_s_rep(g, vertice-1, pos-1);
		//printf("%d >%c<", n, c);
	}

	//printf("le_amigos_}\n");
}

int main(){
	int n, i, aux;

	Grafo g;

	do{

		scanf("%d", &n);

		if(n == 0)
			return 0;

		inic_grafo(&g, n);

		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			le_amigos(g, aux);
		}

		aux = BEP_IMPAR(g, n);

		//printf("%d %d\n", aux, ((aux % 2) == 0));
		//imprime_grafo(g, n);

		if(aux)
			printf("NAO\n");
		else
			printf("SIM\n");

		desaloca(&g, n);

	}while(1);
	return 0;
}