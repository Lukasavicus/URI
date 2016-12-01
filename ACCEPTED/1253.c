/* Lukasavicus 1253 */

#include <stdio.h>
#include <string.h>

int main(){
	
	int TC = 0;
	char string[51];
	int size, offset, i;

	scanf("%d", &TC);

	while(TC--){
		scanf("%s", string);
		size = strlen(string);
		scanf("%d", &offset);
		for(i = 0; i < size; i++){
		    if((string[i]-offset) >= 'A')
			    printf("%c", string[i]-offset);
	        else
	            printf("%c", 26 + string[i]-offset);
		}
		printf("\n");
	}

	return 0;
}