/* Lukasavicus - 1987 */

#include <stdio.h>

int main(){
	
	int size, i, sum;

	char number[11];

	while(scanf("%d", &size) != EOF){
		scanf("%s", number);
		for(i = 0, sum = 0; i < size; i++){
			//printf("n:%d\n", number[i]);
			sum += number[i]-'0';
		}
		printf("%d ", sum);
		if(sum % 3 == 0)
			printf("sim\n");
		else
			printf("nao\n");
	}

	return 0;
}