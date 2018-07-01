/* Lukasavicus - 1192 */

#include <stdio.h>

int main(){
	int TC, a, b;
	char c;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d%c%d", &a, &c, &b);
		if(a == b)
			printf("%d\n", (a*b));
		else if(c >= 'A' && c <= 'Z')
			printf("%d\n", (b-a));
		else
			printf("%d\n", (a+b));
	}
	return 0;
}