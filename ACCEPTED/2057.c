// Lukasavicus 2057

#include <stdio.h>

main(){
	int s, t, f;
	const int mod = 24;

	scanf("%d %d %d", &s, &t, &f);

	if(f < 0){
		f *= -1;
		f = ((mod - (f % mod)) % mod);
	}
	printf("%d\n", ((s+t+f) % mod) );
}
