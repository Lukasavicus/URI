/* Lukasavicus - 1708 */

#include <stdio.h>      /* printf */
#include <math.h>       /* round, floor, ceil, trunc */

int main(){
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.0lf\n", ceil( 1 / ( 1 - ( a / b ) ) ) );
}
