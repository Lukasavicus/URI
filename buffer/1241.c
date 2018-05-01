/* Lukasavicus - 1241 */

#include <stdio.h>
#include <string.h>

int main(){
	
	int TC;
	char string1[1001], string2[1001];
	int size1, size2, i, aux;

	scanf("%d", &TC);

	while(TC--){
		scanf("%s %s", string1, string2);
		size1 = strlen(string1);
		size2 = strlen(string2);

		if(size2 > size1){
			printf("nao encaixa");
		}
		else{
		    aux = size1 - size2;
			for(i = aux; i < size1; i++){
			    //printf(">%c %c\n", string1[i], string2[i - aux]);
				if(string1[i] != string2[i - aux])
					break;
			}
			if(i == size1)
				printf("encaixa\n");
			else
				printf("nao encaixa\n");
		}

	}

	return 0;
}