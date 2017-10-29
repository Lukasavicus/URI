/*  Lukasavicus - 1487 */

#include <stdio.h>
#include <stdlib.h>
typedef struct _attr{
	int d;
	int p;
}Attr;

int compare(const void *a, const void *b){
	Attr * aa = (Attr *) a;
	Attr * ab = (Attr *) b;
	
	double da = aa->p / aa->d;
	double db = ab->p / ab->d;
	
	if(da < db)
		return 1;
	else if(da == db)
		return 0;
	else
		return -1;
	
}

int main(){

	int n, t;
	Attr a[101];
	int i, aux, total, j = 0;
	
	while(1){
		j++;
		total = 0;
		scanf("%d", &n);
		if(n == 0)
			break;
		scanf("%d", &t);
		for(i = 0; i < n; i++){
			scanf("%d %d", &a[i].d, &a[i].p);
		}
printf("work\n");
		qsort(a, n, sizeof(Attr), compare);
printf("work2\n");
		for(i = 0; i < n; i++){
printf("%d %d\n", a [i].d, a [i].p);
			if(t == 0)
				break;
				
			if(a[i].d < t){
				aux = t / a[i].d;
				total += aux * a[i].p;
				t -= aux * a[i].d;
			}
		}
		printf("Instancia %d\n%d\n", j, total);
	}

	return 0;
}