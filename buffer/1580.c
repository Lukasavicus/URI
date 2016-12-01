// Lukasavicus 1580

#include <stdio.h>
#include <string.h>

#define MAX 26
#define MAXSTR 1123

typedef long long int lli;

lli fat(lli n){

	if(n == 1)
		return n;
	return n * fat(n-1);

}

void main(){
	
	lli i, size;
	lli v[MAX];
	lli repeated = 0;

	lli r;
	const lli mod = 1000000007;

	char cv[MAXSTR];

	while(scanf("%s", cv) != EOF){
		repeated = 1;
		size = strlen(cv);
		for(i = 0; i < MAX; i++){
			v[i] = 0;
		}
		for(i = 0; i < size; i++){
			//printf(">%lld\n", cv[i]-'A');
			v[cv[i]-'A']++;
		}

		//for(i = 0; i < size; i++)	printf("%lld\n", v[cv[i]-'A']);

		for(i = 0; i < MAX; i++){
			if(v[i] > 1)
				repeated *= fat(v[i]);
		}

		printf("%lld %lld\n", size, repeated);

		r = fat(size) / repeated;

		r = r % mod;

		printf("%lld\n", r);
	}

}