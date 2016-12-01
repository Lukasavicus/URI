// Lukasavicus 1216

#include <stdio.h>
#include <string.h>

int main(){
	int n = 0;
	double sum = 0;
	int v;
	char c;
	while(getchar() != EOF){
		do{
			c = getchar();
			//printf("%c", c);
		}while(c != '\n');
		//printf(">%c<", c);
		scanf(" %d ", &v);
		//printf("%d\n", v);
		sum += v;
		n++;
	}
	printf("%.1lf\n", sum/n);
	return 0;
}