//Lukasavicus 2242

#include <stdio.h>

int main(){

	char s[52], c, i = 0, j, h;

	while(1){
		scanf("%c", &c);
		if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
			s[i++] = c;
		if(c == '\n')
			break;
	}
	h = i/2;
	for(j = 0, --i; (j < h) && (s[j] == s[i-j]); j++);

	if(j == h)
		printf("S\n");
	else
		printf("N\n");

    return 0;
}