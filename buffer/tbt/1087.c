/* Lukasavicus 1087 */

#include <stdio.h>

int absol(int a, int b){
	return (a > b) ? (a - b) : (b - a);
}

int main(){
	int x1, y1, x2, y2;
	while(1){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(x1 == x2 && y1 == y2){
			if(x1 == y1 && x1 == 0)
				break;
			printf("0\n");
		}
		else if(absol(x1, x2) == absol(y1, y2))
			printf("1\n");
		else
			printf("2\n");
	}
}