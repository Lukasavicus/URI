//Lukasavicus 1015

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float x, y;

}Ponto;

main(){

	Ponto p1, p2;

	scanf("%f %f", &p1.x, &p1.y);
	scanf("%f %f", &p2.x, &p2.y);

	printf("%.4lf\n", sqrt( ((p1.x-p2.x) * (p1.x-p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)) ) );


}
