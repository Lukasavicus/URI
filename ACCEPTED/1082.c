//Lukasavicus 1082

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	char id;
	int group;
}Node;

// Inicia os nos colocando todas as letras como identificadores e separando-os em grupos.
void init_groups(Node n[], int s){
	int i = 0;

	for(i = 0; i < s; i++){
		n[i].id = 97 + i;
		n[i].group = i+1;
	}
}


// Atualiza o identificador do grupo de um no (ou todos os nos ligados a esse no), quando esse no "une-se" a um todo.
void update_groups(Node n[], int s, int g_searched, int g_substitute){
	int i = 0;

	for(i = 0; i < s; i++)
		if(n[i].group == g_searched)
			n[i].group = g_substitute;
}

void print_groups_test(Node n[], int s){
	int i = 0;

	for(i = 0; i < s; i++)
		printf("[%d]: id:%c g:%d\n", i, n[i].id, n[i].group);
	printf("\n");
}

// Conta o numero de grupos pela transicao do numero de identificacao de cada grupo.
void print_groups(Node n[], int s){
	int i = 0, aux, groups = 1;

	printf("%c,", n[0].id);
	for(i = 1, aux = n[0].group; i < s; i++){
		//printf("%d %d\n", n[i].group, aux);
		if(n[i].group != aux){
			printf("\n");
			groups++;
			aux = n[i].group;
		}
		printf("%c,", n[i].id);
	}
	printf("\n%d connected components\n\n", groups);
}

int compar(const void *p1, const void *p2){
   /* The actual arguments to this function are "pointers to
    * pointers to char", but strcmp(3) arguments are "pointers
    * to char", hence the following cast plus dereference
    */

    Node *pnode1 = (Node *) p1;
    Node *pnode2 = (Node *) p2;

    //return ((*pnode1).group - (*pnode2).group);
    return (((*pnode1).group - (*pnode2).group) * 100) + (((*pnode1).id - (*pnode2).id));
}

void main(){
	int n, i;
	int v, e, j;
	char aux, bux, cux;
	char str[3];

	Node *nos;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d %d", &v, &e);

		nos = (Node *) malloc (v * sizeof(Node));
		init_groups(nos, v);

		for(j = 0; j < e; j++){
			scanf(" %c", &aux); 
			scanf(" %c", &bux);
		
			if(nos[aux-97].group > nos[bux-97].group){
				cux = aux;
				aux = bux;
				bux = cux;
			}

			//printf("%d %d %d %d\n", bux-97, nos[bux-97].group, aux-97, nos[aux-97].group);
			update_groups(nos, v, nos[bux-97].group, nos[aux-97].group);
			//print_groups_test(nos, v);

		}
		qsort(nos, v, sizeof(Node), compar);
		printf("Case #%d:\n", i+1);
		print_groups(nos, v);
		//print_groups_test(nos, v);
		free(nos);
	}



}