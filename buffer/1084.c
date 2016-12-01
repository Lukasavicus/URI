/* Lukasavicus - 1084 */

#include <stdio.h>
#include <string.h>

#define BIG 100
#define MAX 112345

//char resp[MAX];
int resp[MAX];
int n_elem = 0;
char N[MAX];

/*
void maxPrize(int size, int d){

	int min = BIG, i_min = -1, i, j;
	
	strcpy(resp, N);
	
	for(i = 0; i < d; i++){
		min = BIG; 
		i_min = -1;
		for(j = 0; j < size; j++){
			if(N[j] < min){
				min = N[j];
				i_min = j;
			}
		}
		if(i_min != -1)
			N[i_min] = BIG;
	}
}
*/


void maxPrize(int size, int d){
	int min = BIG, i_min = -1, i, j, k;
	
	for(i = 0, k = 0; i < 10 && k < d; i++){
		for(j = 0; j < size && k < d; j++){
			if(N[j] == i+'0'){
				N[j] = BIG;
				k++;
			}
		}
	}
}

/*
void maxPrize(int size, int d){
	int min = BIG, i_min = -1, i, j, k;
	
	memset(resp, 0, sizeof(int) * MAX);
	
	for(i = 9, k = 0; i >= 0 && k < d; i--){
		for(j = 0; j < size && k < d; j++){
			if(resp[j] != 1 && N[j] >= i+'0'){
				resp[j] = 1;
				k++;
			}
		}
	}
}
*/


int main(){
	int D, size, i;
	while(1){
		scanf("%d %d", &size, &D);
		scanf("%s", N);
		
		if(size == 0 && D == 0)
			break;
			
		maxPrize(size, D);
		
		for(i = 0; i < size; i++){
			if(N[i] != BIG)
				printf("%c", N[i]);
		}
		printf("\n");
		
	}
	return 0;
}