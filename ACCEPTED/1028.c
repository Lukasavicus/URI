// Lukasavicus 1028

#include <stdio.h>

int mdc(int a, int b){
	if(b == 0)
		return a;

	return mdc(b, a%b);
}

void main(){
	int a, b, res;
	int n, i;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		if(a > b)
			res = mdc(a, b);
		else
			res = mdc(b, a);
		printf("%d\n", res);
	}

}