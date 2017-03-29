//Lukasavicus 2164

#include <stdio.h>
#include <math.h>

int main(){

	int n;
	double d;
	const double sqrt5 = sqrt(5);

	scanf("%d", &n);
	printf("%.1lf\n", ( ( (pow(((1+sqrt5)/2), n)) - (pow(((1-sqrt5)/2), n)) )/sqrt5 ) );

    return 0;
}