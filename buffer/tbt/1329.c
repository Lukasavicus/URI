/* Lukasavivus 1329 */

#include <stdio.h>

int main(){
	int n, d, j, m;
	while(1){
		j = 0;
		m = 0;
		scanf("%d", &n);
		if(n == 0)
			break;
		while(n--){
			scanf("%d", &d);
			if(d)
				j++;
			else
				m++;
		}
		printf("Mary  won %d times and John  won %d times", m, j);
	}
}