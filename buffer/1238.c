/* Lukasavicus 1238 */

#include <stdio.h>
#include <string.h>

int main (){

	int size1, size2, i, j, min;
	char string1[51], string2[51], stringF[101];
	int TC;
	
	scanf("%d", &TC);
	
	while(TC--){
		scanf("%s %s", string1, string2);
		size1 = strlen(string1);
		size2 = strlen(string2);
		
		min = (size1 > size2) ? size2 : size1;
		
		for(i = 0, j = 0; i < min; i++){
			stringF[j++] = string1[i];
			stringF[j++] = string2[i];
		}
		j--;
		
		if(size1 > size2){
			for(i = min-1; i < size1; i++){
				stringF[j++] = string1[i];
			}
		}
		else{
		 	for(i = min-1; i < size2; i++){
				stringF[j++] = string2[i];
			}
		}
		stringF[j] = '\0';
		printf("%s\n", stringF);
	}

	return 0;
}