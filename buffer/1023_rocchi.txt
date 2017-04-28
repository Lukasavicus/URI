//Lukasavicus 1023

#include <stdio.h>
#include <stdlib.h>

#define MAX 1123456

typedef struct _consumo{
  int n_habit;
  int litros;
  int media;
} Consumo;

Consumo consumidores[MAX];

void zerar(){
	int i;
	for(i = 0; i < MAX; i++){
		consumidores[i].n_habit = 0;
		consumidores[i].litros = 0;
		consumidores[i].media = 0;
	}

}

int compare(const void *a, const void *b){
  Consumo *ac, *bc;
  ac = (Consumo *) a;
  bc = (Consumo *) b;
  return ac->media - bc->media;
  //return ac->litros - bc->litros;
}

int main(){

  int n, i, j, aux, sum;
  unsigned int auxInt;
  float n_habits = 0, litros = 0, mediaTotal;
  i = 0;
  while(1){
    i++;
    n_habits = 0;
    litros = 0;
    scanf("%d", &n);
    if(n == 0)
      break;
    for(j = 0; j < n; j++){
      scanf("%d %d", &consumidores[j].n_habit, &consumidores[j].litros);

      consumidores[j].media = consumidores[j].litros / consumidores[j].n_habit;

      n_habits += consumidores[j].n_habit;
      litros += consumidores[j].litros;
    }

    qsort(consumidores, n, sizeof(Consumo), compare);

    printf("Cidade# %d:\n", i);
    for(j = 0, sum = 0; j < n-1; j++){
      aux = j+1;
      if(consumidores[j].media == consumidores[aux].media){
      	sum += consumidores[j].n_habit;
      	while(consumidores[j].media == consumidores[aux].media){
      	  sum += consumidores[aux].n_habit;
          aux++;
      	}
      	printf("%d-%d ", sum, consumidores[j].media);
      	j = aux-1;
      }
      else{
        printf("%d-%d ", consumidores[j].n_habit, consumidores[j].media);
  	  }
    }

    printf("%d-%d\n", consumidores[j].n_habit, consumidores[j].media);
    
    mediaTotal = (litros / n_habits);// - 0.009999999;

    //printf("0:%.5f\n", mediaTotal);
    mediaTotal = (mediaTotal * 10);
    mediaTotal = (mediaTotal * 10);
    //printf("1:%.5f\n", mediaTotal);
    auxInt = mediaTotal / 1;
    //printf("2:%d\n", auxInt);
    mediaTotal = auxInt / 100.00;
    
    printf("Consumo medio: %.2f m3.\n\n", mediaTotal);
    zerar();
  }


  return 0;
}
