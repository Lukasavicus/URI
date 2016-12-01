// Lukasavicus 1234

#include <stdio.h>

int main (){

	int isUpper = 0, isFirst = 1, i;
	char string[51],caux;
	
	while(1){
		i=0;
		while(1){
			if(scanf("%c", &caux) == EOF){
				return 0;
			}
			else if(caux == '\n'){
				break;
			}
			else if(caux == ' '){
				string[i] = caux;
			}
			else{
				if(isFirst){
					isFirst = 0;
					if(caux >= 'A' && caux <= 'Z'){
						isUpper = 1;
					}
					string[i] = caux;
				}
				else{
					if(caux >= 'A' && caux <= 'Z'){
						if(isUpper){
							string[i] = caux + ('a' - 'A');
						}
						else{
							string[i] = caux; 
						}
					}
					else{
						if(isUpper){
							string[i] = caux;
						}
						else{
							string[i] = caux - ('a' - 'A');
						}
					}
					isUpper = !isUpper;
				}
			}
				
			i++;
		}
		string[i] = '\0';
		printf("%s\n", string);
	}

	return 0;
}