/* Lukasavicus - 2159 */

#include <stdio.h>
#include <math.h>

int main(){

	double v, m, M;

	scanf("%lf", &v);

	m = v / log(v);
	M = 1.25506 * m;

	printf("%.1lf %.1lf\n", m, M);

	return 0;
}