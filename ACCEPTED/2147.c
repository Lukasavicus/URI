/* Lukasavicus - 2147 */

#include <stdio.h>
#include <string.h>

int main(){

	char str[11234];
	double r;
	const double hundred = 100;
	int TC;

	scanf("%d", &TC);

	while(TC--){
		scanf("%s", str);

		r = strlen(str) / hundred;
		printf("%.2lf\n", r);
	}

	return 0;
}