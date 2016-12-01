/* Lukasavicus - 1574 */

#include <stdio.h>
#include <string.h>

#define MAX 101

int main(){

	int TC, n, inst[MAX], i, p, aux;

	char instruction[10];

	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &n);
		for(i = 0, p = 0; i < n; i++){
			scanf("%s", instruction);
			if(strcmp(instruction, "LEFT") == 0){
				inst[i] = -1;
				p--;
			}
			else if(strcmp(instruction, "RIGHT") == 0){
				inst[i] = 1;
				p++;
			}
			else if(strcmp(instruction, "SAME") == 0){
				scanf("%s", instruction);
				scanf("%d", &aux);
				aux--;
				p += inst[aux];
				inst[i] = inst[aux];
			}
			//printf("actual P: %d\n", p);
		}
		printf("%d\n", p);
	}

	return 0;
}