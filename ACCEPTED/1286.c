//Lukasavicus 1286

#include <stdio.h>

typedef struct _Pedido{
	int tempo;
	int nPizza;
} Pedido;


int calc(int nPedidos, int limite, int max, int tempo, Pedido vetPed[], int passo){

// ------------------------------------------------------------------

	if(max > limite)
		return -1;

	if(passo >= nPedidos)
		return tempo;

// ------------------------------------------------------------------

	int n1 = 0, n2 = 0;

	n1 = calc(nPedidos, limite, (max + vetPed[passo].nPizza), (tempo + vetPed[passo].tempo), vetPed, passo+1);
	n2 = calc(nPedidos, limite, max, tempo, vetPed, passo+1);

//printf("np:%d\tl:%d\tm:%d\tt:%d\t_np%d\t_t%d\tP%d\t->\tn1:%d\tn2:%d\n", nPedidos, limite, max, tempo, vetPed[passo].nPizza, vetPed[passo].tempo, passo, n1, n2);

// ------------------------------------------------------------------

	tempo = (n1 > n2 ? n1 : n2);

	return tempo; //(n1 > n2 ? n1 : n2) +

}

main(){


	int nPedidos;
	int limite;
	int melhorTempo;

	Pedido vetPed[31];

	while(1){
		scanf("%d", &nPedidos);

		if(nPedidos == 0)
			return;

		scanf("%d", &limite);

		int i;

		for(i = 0; i < nPedidos; i++){
			scanf("%d %d", &vetPed[i].tempo, &vetPed[i].nPizza);
		}

		//melhorTempo = calculo(nPedidos, limite, vetPed, -1);

		melhorTempo = calc(nPedidos, limite, 0, 0, vetPed, 0);

		printf("%d min.\n", melhorTempo);

	}
}