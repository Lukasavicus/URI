// Lukasavicus 1582

#include <stdio.h>

int mdc(int a, int b){

	if(a < b){
		int c;
		c = a;
		a = b;
		b = c;
	}

	if(b == 0)
		return a;
	return mdc(b, a%b);
}

void main(){
	
	int a, b, c;
	int testPit = 0, testPri = 0;

	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		testPit = ((a*a) == ((b*b)+(c*c))) || ((b*b) == ((a*a)+(c*c))) || ((c*c) == ((b*b)+(a*a)));
		testPri = (mdc(a, b) == 1) && (mdc(a, c) == 1) && (mdc(b, c) == 1);

		if(testPit){
			if(testPri){
				printf("tripla pitagorica primitiva\n");
			}
			else{
				printf("tripla pitagorica\n");
			}				
		}
		else{
			printf("tripla\n");
		}
	}

}