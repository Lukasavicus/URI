/* Lukasavicus 1235 */

#include<stdio.h>

int main(){

	char string[101], caux, response[101];
	int TC, size, i, j, iaux;
	
	scanf("%d", &TC);
	
	while(TC--){
		size = 0;
		while(1){
			scanf("%c", &caux);
			if(caux == '\n')
				break;
			else
				string[size++] = caux;
		}
		string[size] = '\0';
		iaux = ((size-1)/2)-1;
		for(i = iaux, j = 0; i >= 0; i--, j++)
			response[j] = string[i];

		 for(i = (size-1), j = iaux+1; i > iaux; i--, j++)
			response[j] = string[i];
			
		response[size] = '\0';
		printf("%s", response);
	}

	return 0;
}