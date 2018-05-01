// Lukasavicus 1867

#include <stdio.h>
#include <string.h>

#define MAX 101

int reduct(char *s){
	int len = strlen(s);
	int i, sum, aux_sum;

	for(i = 0, sum = 0; i < len; i++){
		sum += (s[i] - '0');
	}

	while(sum > 10){
		aux_sum = sum;
		sum = 0;
		while(!aux_sum){
			sum += (aux_sum % 10);
			aux_sum /= 10;
		}
	}
	if(sum == 10)
		return 1;
	return sum;
}

int main(){
	
	char s1[MAX], s2[MAX];
	char garbage;
	int n1, n2;

	while(1){
		scanf("%s %s", &s1, &s2);
		if(((strlen(s1) == 1) && (strlen(s2) == 1)) && ((s1[0] == '0') && (s2[0] == '0')))
			return 0;
		n1 = reduct(s1);
		n2 = reduct(s2);
		//printf("%d %d\n", n1, n2);
		(n1 > n2) ? printf("1\n") : ((n1 < n2) ? printf("2\n") : printf("0\n"));
	}

	return 0;
}