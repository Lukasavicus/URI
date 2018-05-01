//Lukasavicus 1524
#include <stdio.h>
 
#define MAX     1123456
#define MAXK    1001
 
int vet[MAX];
int outro[MAX];
 
void bubble(int vet[], int size){
    int i, j, aux;
    for(i = 0; i < size; i++)
        for(j = i + 1; j < size; j++)
            if(vet[j] < vet[i]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
}
 
void print(int vet[], int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("\n");
}
 
int abs(int a, int b){
    return (a > b) ? (a - b) : (b - a);
}
 
main(){
    int size, k;
 
    while(scanf("%d", &size) == 1){
        size--;
        scanf("%d", &k);
 
        int i;
        for(i = 0; i < size; i++){
            scanf("%d", &vet[i]);
        }
 
        //print(vet, size);
 
        outro[0] = vet[0];
        for(i = 1; i < size; i++){
            //printf("%d %d\n", vet[i], vet[i-1]);
            outro[i] = abs(vet[i-1], vet[i]);
        }
 
        //print(outro, size);
        bubble(outro, size);
        //print(outro, size);
 
        size -= k;
        int max = 0;
        for(i = 0; i <= size; i++)
            max += outro[i];
 
        printf("%d\n", max);
 
    }
 
}