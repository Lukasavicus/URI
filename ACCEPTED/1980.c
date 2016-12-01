/* Lukassavicus - 1980 */

#include <stdio.h>
#include <string.h>

#define TOT 26
#define MAX 15

int duplicadas[TOT];

void reset(){
	int i = 0;
	for(i = 0; i < TOT; i++)
	duplicadas[i] = 0;
}

long long int fat(int n){
	if(n == 0)
		return 1;
	return n * fat(n-1);
}

int main(){
	
	char number[MAX];

	int total, i;
	long long int dup, result;

	while(1){
		scanf("%s", number);
		dup = 1;
		total = strlen(number);
		if(strcmp(number, "0") == 0)
			break;

		reset();

		for(i = 0; i < total; i++){
			duplicadas[number[i]-'a']++;
		}

		/*
		for(i = 0; i < total; i++)
			printf("[%d]: %d\n", i, duplicadas[i]);
		*/

		for(i = 0; i < total; i++){
			if(duplicadas[i] > 1)
				dup *= fat(duplicadas[i]);
		}

		result = fat(total) / dup;

		printf("%lld\n", result);

	}

	return 0;

}