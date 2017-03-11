//Lukasavicus 2029

#include <stdio.h>

#define PI 3.14

int main(){
	double v, d;

	while(scanf("%lf %lf", &v, &d) != EOF){
  		printf("ALTURA = %.2lf\nAREA = %.2lf\n", (v / ((d/2)*(d/2)*PI)), ((d/2)*(d/2)*PI));
	}

	return 0;

}