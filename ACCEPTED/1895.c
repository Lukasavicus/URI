// Lukasavicus 1895

#include <stdio.h>

#define MAX 60

int mod_diff(int a, int b){
	return (a > b) ? (a - b) : (b - a );
}

main(){
	
	int n, top, card, l, pa = 0, pb = 0, i;

	scanf("%d %d %d", &n, &top, &l);
	n--;
	for(i = 0; i < n; i++){
		scanf("%d", &card);
		if(mod_diff(top, card) <= l){
			//printf("%d %d %d\n", top, card, l);
			if(i % 2 == 0)
				pa += mod_diff(top, card);
			else
				pb += mod_diff(top, card);

			top = card;
		}
	}
	printf("%d %d\n", pa, pb);

}