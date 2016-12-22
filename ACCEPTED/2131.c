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

	int Kosaraju_Sharir(Grafo g, int tam);

	void BEL(Grafo g, int tam, int id_root, int modo);
	void BEP_AUX(Grafo g, int id_root, int modo, int * tempo, int id_grupo);
	void BEP(Grafo g, int tam, int id_root, int modo, int * tempo);
	void ALL_BEP(Grafo g, int tam, int id_root, int modo, int * tempo);

	int BEP_IMPAR(Grafo g, int tam);
	int BEP_IMPAR_AUX(Grafo g, int id_root, int *coloracao, int ncor);

	int Tarjan(Grafo g, int tam);
	void BEP_CC(Grafo g, int tam, int v, int pre[], int low[], int stack[], int sc[], int *conta, int *k, int *N);

	void imprime_grafo(Grafo g, int tam, int modo_peso);
	void imprime_vertice(Grafo g, int id_root);
	void imprime_lista_adjacencias(Grafo g, int tam);
	void imprime_lista_adjacencias_vertice(Grafo g, int id_root);
	void imprime_caminho_raiz_vertice(Grafo g, int id_root);
	void imprime_em_largura(Grafo g, int tam, int id_root);
	void imprime_em_profundidade(Grafo g, int tam, int id_root);
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





// ============================================== Buscas ===========================================

	// E se tivermos mais de uma componente conexa ?
	void BEL(Grafo g, int tam, int id_root, int modo){

		if(estaVazia(g))
			return;

		int * stack;

		stack = (int *)malloc(tam * sizeof(int));
		int sstack = 0; // Size of Stack

		int i, j, aux1, aux2;

		stack[sstack++] = id_root;

		Vertice * p;

		int predecessor = -1;

		g[id_root].distancia = 0;

		for(i = 0; i < sstack; i++){
			aux1 = stack[i];

			if(modo) printf("Visitando: %d\n", aux1);

			g[aux1].cor = CINZA;
			// === Making the visit ===
			p = g[aux1].prox;
			while(p != NULL){
				aux2 = p->info;
				if(g[aux2].cor == BRANCO){
					if(modo) printf("\tPara visitar: %d\n", aux2);
					stack[sstack++] = aux2;
					g[aux2].cor = CINZA;
					g[aux2].distancia = g[aux1].distancia + 1;
					g[aux2].predecessor = aux1;
				}
				p = p->prox;
			}
			// ++++++++++++++++++++++++

			if(modo) printf("Visitado: %d\n", aux1);

			g[stack[i]].cor = PRETO;
		}
	}
	/*
	void BEL_CaminhosPonderadosMinimos(Grafo g, int tam, int id_root, int modo){

		if(estaVazia(g))
			return;

		Lista fila_de_prioridades;

		lista_inic_lista(&fila_de_prioridades);

		int i, j, aux1, aux2;

		lista_insere_ordenado_iter(&fila_de_prioridades, id_root);

		Vertice * p;

		int predecessor = -1;

		g[id_root].distancia = 0;

		while(fila_de_prioridades != NULL){
			aux1 = lista_exclui_inicio(&fila_de_prioridades);

			if(modo) printf("Visitando: %d\n", aux1);

			g[aux1].cor = CINZA;
			// === Making the visit ===
			p = g[aux1].prox;
			while(p != NULL){
				aux2 = p->info;
				if(g[aux2].cor == BRANCO){
					if(modo) printf("\tPara visitar: %d\n", aux2);
					lista_insere_ordenado_iter(&fila_de_prioridades, aux2);
					g[aux2].cor = CINZA;
					g[aux2].distancia = g[aux1].distancia + 1;
					g[aux2].predecessor = aux1;
				}
				p = p->prox;
			}
			// ++++++++++++++++++++++++

			if(modo) printf("Visitado: %d\n", aux1);

			g[aux1].cor = PRETO;
		}
	}
	*/

	int minimoDaFila(int stack[], int ini, int end){
		int min = BIGGEST;
		int i;
		for(i = ini; i < end; i++){
			if(min < stack[i]);
				min = stack[i];
		}
		return min;
	}

	void BEL_CaminhosPonderadosMinimos(Grafo g, int tam, int id_root, int modo){

		if(estaVazia(g))
			return;

		int * stack;

		stack = (int *)malloc(tam * sizeof(int));
		int sstack = 0; // Size of Stack

		int i, j, aux1, aux2;

		stack[sstack++] = id_root;

		Vertice * p;

		int predecessor = -1;

		g[id_root].distancia = 0;

		for(i = 0; i < sstack; i++){
			aux1 = minimoDaFila(stack, i, sstack);
			//aux1 = stack[i];

			if(modo) printf("Visitando: %d\n", aux1);

			g[aux1].cor = CINZA;
			// === Making the visit ===
			p = g[aux1].prox;
			while(p != NULL){
				aux2 = p->info;
				if(g[aux2].cor == BRANCO){
					if(modo) printf("\tPara visitar: %d\n", aux2);
					stack[sstack++] = aux2;
					g[aux2].cor = CINZA;
					g[aux2].distancia = g[aux1].distancia + 1;
					g[aux2].predecessor = aux1;
				}
				p = p->prox;
			}
			// ++++++++++++++++++++++++

			if(modo) printf("Visitado: %d\n", aux1);

			g[stack[i]].cor = PRETO;
		}
	}

	// E se tivermos mais de uma componente conexa ?
	void BEP_AUX(Grafo g, int id_root, int modo, int * tempo, int id_grupo){
		if(modo) printf("Visitando: %d\n", g[id_root].info);

		g[id_root].cor = CINZA;
		g[id_root].id_grupo = id_grupo;
		g[id_root].tempo_descoberta = *tempo;
		(*tempo) = (*tempo) + 1;

		Vertice * p;
		p = g[id_root].prox;

		while(p != NULL){
			int aux = p->info;
			if(g[aux].cor == BRANCO){

				if(modo) printf("Para visitar: %d\n", aux);

				g[aux].predecessor = id_root;
				BEP_AUX(g, aux, modo, tempo, id_grupo);
			}
			p = p->prox;
		}

		if(modo) printf("Visitado: %d\n", g[id_root].info);

		g[id_root].cor = PRETO;
		g[id_root].tempo_finalizacao = *tempo;
		(*tempo) = (*tempo) + 1;
	}

	void BEP(Grafo g, int tam, int id_root, int modo, int * tempo){
		int i;
		for(i = 0; i < tam; i++)
			if(g[i].cor == BRANCO)
				BEP_AUX(g, id_root, modo, tempo, 0);
	}

	void ALL_BEP(Grafo g, int tam, int id_root, int modo, int * tempo){
		int i;

		if(g[id_root].cor == BRANCO)
			BEP_AUX(g, id_root, modo, tempo, 0);

		for(i = 0; i < tam; i++)
			if(g[i].cor == BRANCO)
				BEP_AUX(g, i, modo, tempo, 0);
	}

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
					//imprime_grafo(g, tam, SEM_PESO);
					//for(j = 0; j < tam; ++j)	printf("c[%d]:%d ", j, coloracao[j]);	printf("\n");
					return 1;
				}
			}
		}

		//imprime_grafo(g, tam, SEM_PESO);
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





// ======================================= COMPONENTES CONEXAS =====================================

	Grafo transpor_grafo(Grafo g,int tam){
		Grafo gt;
		inic_grafo(&gt, tam);
		int i;

		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				while(p != NULL){
					insere_rep_fim(gt, p->info, i, SEM_REP, SEM_PESO);
					p = p->prox;
				}
			}
		}	
		return gt;
	}

	// Algoritmo de Kosaraju-Sharir
	/*
	 * Retorna se existe somente uma componente fortemente conexa
	 */
	int Kosaraju_Sharir(Grafo g, int tam){
		Grafo gt;
		
		int i, j, k;

		int tempo = 0;

		int max = -1, imax = 0;

		gt = transpor_grafo(g, tam);

		ALL_BEP(g, tam, 0, 0, &tempo);

		tempo = 0;

		for(j = 0, max = -1, imax = -1; j < tam; j++){
			if(gt[j].tempo_descoberta == TZERO && g[j].tempo_finalizacao > max){
				max = g[j].tempo_finalizacao;
				imax = j;
			}
		}
		if(imax != -1){
			BEP_AUX(gt, imax, 0, &tempo, 0);
		}

		for(i = 0; i < tam; i++){
			if(gt[i].id_grupo != 0)
				return 0;
		}
		return 1;
	}

	Grafo CFC(Grafo g, int tam, int id_root, int * id_grupo){
		Grafo gt;
		
		int i, j, k;

		int tempo = 0;

		int max = -1, imax = 0;

		gt = transpor_grafo(g, tam);

		ALL_BEP(g, tam, id_root, 0, &tempo);

		imprime_lista_adjacencias(g, tam);
		printf("\n");

		//imprime_grafo(gt, tam);

		//imprime_lista_adjacencias(gt, tam);

		//printf("\n");

		tempo = 0;

		for(i = 0; i < tam; i++){
			for(j = 0, max = -1, imax = -1; j < tam; j++){
				printf("[%d] %d == %d && %d > %d\n", j, gt[j].tempo_descoberta, TZERO, g[j].tempo_finalizacao, max);
				if(gt[j].tempo_descoberta == TZERO && g[j].tempo_finalizacao > max){
					max = g[j].tempo_finalizacao;
					imax = j;
				}
			}
			//printf(">>%d %d\n", max, imax);
			printf("Lista1:\n"); imprime_lista_adjacencias(gt, tam); printf("\n");
			if(imax != -1){
				int i;
				BEP_AUX(gt, imax, 0, &tempo, *id_grupo);
			}
			else{
				break;
			}
			//printf(">>%d %d\n", max, imax);
			//printf("Lista2:\n"); imprime_lista_adjacencias(gt, tam); printf("\n");
			(*id_grupo)++;
		}

		//printf("Lista3:\n");
		imprime_lista_adjacencias(gt, tam);

		return gt;
	}
	

	int numero_de_componentes(Grafo g, int tam){
		Grafo g_cfc;
		int id_grupo_max = 0, i;
		//g_cfc = CFC(g, tam, 0, &id_grupo_max);
		g_cfc = CFC(g, tam, 0, &id_grupo_max);

		/* ACHO QUE ISSO EH MEIO GAMBIARRA */
		/*
		for(i = 0; i < tam; i++)
			if(g_cfc[i].id_grupo == SEM_GRUPO)
				return 0;
		*/

		return id_grupo_max;
	}

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
			peso[i] = BIGGEST;
			listaQ[i] = 1;
		}
		peso[id_root] = 0;
		g[id_root].predecessor = id_root;

		while(Qsize--){
			min = BIGGEST;
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




// =================================== ARVORE DE CAMINHOS MINIMOS ==================================
	void Dijsktra(Grafo g, int tam, int id_root){
		int i, min, i_min;

		int peso_aresta;

		int * listaS;
		int Ssize = tam;

		int * dist;

		Vertice * v;

		dist = (int *) malloc(tam * sizeof(int));
		listaS = (int *) malloc(tam * sizeof(int));

		for(i = 0; i < tam; i++){
			dist[i] = BIGGEST;
			listaS[i] = 1;
		}
		dist[id_root] = 0;
		g[id_root].predecessor = id_root;

		while(Ssize--){
			min = BIGGEST;
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
				peso_aresta = peso_da_aresta(g, i_min, v->info) + dist[i_min];
				//printf("w:[%d][%d] : %d\n", i_min, v->info, peso_aresta);
				if(listaS[v->info] && dist[v->info] > peso_aresta){
					dist[v->info] = peso_aresta;
					g[v->info].predecessor = i_min;
				}
				v = v->prox;
			}
			//printf("\n");
		}
	}

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
			dist[i] = BIGGEST;
			listaS[i] = 1;
		}
		dist[id_root] = g[id_root].peso;
		g[id_root].predecessor = id_root;

		while(Ssize--){
			min = BIGGEST;
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

	// Negative Cycle
	int Floyd_Warshall(Grafo g, int tam){
		int ** minDist;
		int i, j, k;
		int l, m;

		minDist = (int **) malloc(tam * sizeof(int));

		for(i = 0; i < tam; i++){
			minDist[i] = (int *)malloc(tam * sizeof(int));
		}

		for(i = 0; i < tam; i++){
			for(j = 0; j < tam; j++){
				if(i != j)
					minDist[i][j] = BIGGER;
				else
					minDist[i][j] = 0;
			}
		}


		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				while(p != NULL){
					minDist[i][p->info] = p->peso;
					p = p->prox;
				}
			}
		}


		for(k = 0; k < tam; k++){
			for(i = 0; i < tam; i++){
				for(j = 0; j < tam; j++){
					if(minDist[i][j] > minDist[i][k] + minDist[k][j]){
						minDist[i][j] = minDist[i][k] + minDist[k][j];
					}
					/*
						for(l = 0; l < tam; l++){
							for(m = 0; m < tam; m++){
								printf("%d ", minDist[l][m]);
							}
							printf("\n");
						}
						printf("\n>\n");
					*/
				}
			}
		}

		for(i = 0; i < tam; i++){
			if(minDist[i][i] < 0)
				return 1;
		}
		return 0;
	}

	// Negative-Cycles (if have: 1, ow: 0);
	int Bellman_Ford_Moore(Grafo g, int tam, int id_root){
		int i, j;
		int l,m;

		for(i = 0; i < tam; i++){
			g[i].predecessor = RAIZ;
			g[i].distancia = BIG;
		}
		g[id_root].distancia = 0;

		Vertice * p;
		if(!estaVazia(g)){
			for(i = 0; i < tam-1; i++){
				for(j = 0; j < tam; j++){
					p = g[j].prox;
					while(p != NULL){
						if((g[p->info].distancia + p->peso) < g[j].distancia){
							g[j].distancia = g[p->info].distancia + p->peso;
							g[j].predecessor = p->info;
						}
						p = p->prox;
					}
				}
				/*
				printf("Dist:\n");
				for(l = 0; l < tam; l++){
					printf("%d ", g[l].distancia);
				}
				printf("\nPred:\n");
				for(l = 0; l < tam; l++){
					printf("%d ", g[l].predecessor);	
				}
				printf("\n\n");
				*/
			}
		}

		if(!estaVazia(g)){
			for(i = 0; i < tam; i++){
				p = g[i].prox;
				while(p != NULL){
					if((g[p->info].distancia + p->peso) < g[i].distancia){
						return 1;
					}
					p = p->prox;
				}
			}
		}

		return 0;
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

	void imprime_vertice(Grafo g, int id_root){
		int i;

		Vertice * p;
		if(!estaVazia(g)){
			p = g[id_root].prox;
			printf("I[%d]: ",  id_root);
			while(p != NULL){
				printf("%d ",  p->info);
				p = p->prox;
			}
			printf("\n");
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

	void imprime_lista_adjacencias_vertice(Grafo g, int id_root){
		if(!estaVazia(g)){
				printf("I[%d]\td:%d\tp:%d\ttd:%d\ttf:%d\tig:%d\n",  id_root, g[id_root].distancia, g[id_root].predecessor, g[id_root].tempo_descoberta, g[id_root].tempo_finalizacao, g[id_root].id_grupo);
		}	
	}

	void imprime_caminho_raiz_vertice(Grafo g, int id_root){
		if(g[id_root].predecessor != RAIZ) //g[id_root].predecessor != id_root // TODO: Adotar um padrao, onde a raiz de um grafo eh representada por um numero fixo (ex.: -1) ou eh representada pelo mesmo numero do vertice (ex.: vertice 5: root(5) = 5)
			imprime_caminho_raiz_vertice(g, g[id_root].predecessor);

		printf("%d\n", id_root);
	}

	void imprime_caminho_raiz_vertice_v2(Grafo g, int id_root){
		if(g[id_root].predecessor != id_root)
			imprime_caminho_raiz_vertice_v2(g, g[id_root].predecessor);

		printf("%d\n", id_root);
	}

	void imprime_em_largura(Grafo g, int tam, int id_root){
		BEL(g, tam, id_root, 1);
	}

	void imprime_em_profundidade(Grafo g, int tam, int id_root){
		int t;
		BEP(g, tam, id_root, 1, &t);
	}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






// ==================================================================================================================================================

	void Test(){
		Grafo g;
		int t = 6;
		int aux;

		inic_grafo(&g, t);

		printf("insere\n");

		insere_rep_fim(g, 1, 0, SEM_REP, SEM_PESO);	insere_rep_fim(g, 0, 1, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 2, 0, SEM_REP, SEM_PESO);	insere_rep_fim(g, 0, 2, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 3, 1, SEM_REP, SEM_PESO);	insere_rep_fim(g, 1, 3, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 5, 2, SEM_REP, SEM_PESO);	insere_rep_fim(g, 2, 5, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 4, 3, SEM_REP, SEM_PESO);	insere_rep_fim(g, 3, 4, SEM_REP, SEM_PESO);

		//insere_rep_fim(g, 4, 2, SEM_REP, SEM_PESO);	insere_rep_fim(g, 2, 4, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 4, 5, SEM_REP, SEM_PESO);	insere_rep_fim(g, 5, 4, SEM_REP, SEM_PESO);

		printf("imprime_grafo\n");
		imprime_grafo(g, t, SEM_PESO);

		printf("BEP_IMPAR\n");
		aux = BEP_IMPAR(g, t);

		printf("Cycle: %d\n", aux);

		printf("imprime_grafo\n");
		imprime_grafo(g, t, SEM_PESO);

		//desaloca(&g, t);
	}

	void TestT(){
		Grafo g;
		Grafo gt;
		Grafo g_cfc;
		int t = 8;
		int aux;

		printf("inic_grafo\n");
		inic_grafo(&g, t);

		//printf("imprime_grafo\n");
		//imprime_grafo(g, t, SEM_PESO);

		printf("insere\n");
		
		insere_rep_fim(g, 0, 2, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 1, 0, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 1, 3, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 2, 1, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 2, 3, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 2, 4, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 3, 5, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 4, 5, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 4, 6, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 5, 3, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 5, 7, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 6, 4, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 6, 7, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 7, 7, SEM_REP, SEM_PESO);
		
		
		
		printf("imprime_grafo\n");
		imprime_grafo(g, t, SEM_PESO);

		/*

		printf("Transpoe Grafo\n");
		gt = transpor_grafo(g, t);

		printf("imprime_grafo\n");
		imprime_grafo(gt, t);
		*/
		int id_grupo = 0;
		g_cfc = CFC(g, t, 0, &id_grupo);

		imprime_lista_adjacencias(g_cfc, t);
	}

	void TestConex(){
		Grafo g;
		int t = 4;

		inic_grafo(&g, t);

		insere_rep_fim(g, 0, 1, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 0, 2, SEM_REP, SEM_PESO); insere_rep_fim(g, 2, 0, SEM_REP, SEM_PESO);

		insere_rep_fim(g, 1, 3, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 2, 3, SEM_REP, SEM_PESO);
		insere_rep_fim(g, 3, 0, SEM_REP, SEM_PESO); insere_rep_fim(g, 0, 3, SEM_REP, SEM_PESO);

		int aux = numero_de_componentes(g, t);

		if(aux == 0)
			printf("S\n");
		else
			printf("N\n");
	}

	void Test1128(){
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
				insere_rep_fim(g, a-1, b-1, SEM_REP, SEM_PESO);
				if(d == 2)
					insere_rep_fim(g, b-1, a-1, SEM_REP, SEM_PESO);
			}
			//aux = numero_de_componentes(g, n);
			aux = Kosaraju_Sharir(g, n);
			printf(">>>>%d\n", aux);
			if(aux == 1)
				printf("1\n");
			else
				printf("0\n");
			desaloca(&g, n);
		}while(1);
	}

	void le_amigos(Grafo g, int pos){
		char c = ' ';
		int i = 0, vertice = 0;
		//printf("le_amigos_{\n");
		while(c == ' '){
			scanf("%d%c", &vertice, &c);
			insere_rep_fim(g, pos-1, vertice-1, SEM_REP, SEM_PESO);
			insere_rep_fim(g, vertice-1, pos-1, SEM_REP, SEM_PESO);
			//printf("%d >%c<", n, c);
		}

		//printf("le_amigos_}\n");
	}

	int Test1979(){
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

	void Test1205(){

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

			//imprime_lista_adjacencias(g, n);
			//imprime_caminho_raiz_vertice_v2(g, end-1);

		}
	}

	void Test1774(){
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
	void Test10004(){
		int n, m, a, b, i;
		int result;
		Grafo g;

		while(1){
			scanf("%d", &n);

			if(n == 0)
				break;

			scanf("%d", &m);
			inic_grafo(&g, n);
			for(i = 0; i < m; i++){
				scanf("%d %d", &a, &b);
				insere_rep_fim(g, a, b, SEM_REP, 0);
				insere_rep_fim(g, b, a, SEM_REP, 0);
			}
			//imprime_grafo(g, n, SEM_PESO);
			result = BEP_IMPAR(g, n);
			if(result)
				printf("NOT BICOLORABLE\n");
			else
				printf("BICOLORABLE\n");
		}
	}
	void Test_BF(){
		int n, m, a, b, c, TC = 0, i;
		int result;
		Grafo g;

		scanf("%d", &TC);

		while(TC--){
			scanf("%d %d", &n, &m);
			inic_grafo(&g, n);
			for(i = 0; i < m; i++){
				scanf("%d %d %d", &a, &b, &c);
				insere_rep_fim(g, a, b, SEM_REP, c);
			}
			//result = Floyd_Warshall(g, n);
			result = Bellman_Ford_Moore(g, n, 0);
			if(result)
				printf("possible\n");
			else
				printf("not possible\n");
		}
	}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



int main(){
	int n, m, i, j = 1, a, b, result;
	Grafo g;

	while(scanf("%d %d", &n, &m) != EOF){
		inic_grafo(&g, n);
		for(i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			insere_inicio(g, a-1, b-1, SEM_PESO);
			insere_inicio(g, b-1, a-1, SEM_PESO);
		}
		result = BEP_IMPAR(g, n);
		printf("Instancia %d\n", j);
		if(result)
			printf("nao\n");
		else
			printf("sim\n");

		printf("\n");

		j++;
		desaloca(&g,n);

	}

	return 0;
}















