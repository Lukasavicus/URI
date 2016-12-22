/* Lukasavicus - 2165 */

#include <stdio.h>

int main(){

	char c;
	int i = -1;

	do{
		scanf("%c", &c);
		i++;
	}while(c != '\0' && c != '\n');
	
	if(i <= 140){
		printf("TWEET\n");
	}
	else{
		printf("MUTE\n");
	}

	return 0;
}