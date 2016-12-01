/* Lukasavicus 1332 */

#include <stdio.h>
#include <string.h>

int main(){
	
	int TC = 0;
	char string[6];
	int size, test;

	scanf("%d", &TC);

	while(TC--){
		scanf("%s", string);
		size = strlen(string);
		if(size == 3){
			test = (string[0] == 'o') + (string[1] == 'n') + (string[2] == 'e');
			if(test >= 2)
				printf("1\n");
			else
				printf("2\n");
		}
		else{
			printf("3\n");
		}
	}

	return 0;
}