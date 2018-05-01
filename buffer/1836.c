// Lukasavicus 1836

#include <stdio.h>
#include <math.h>

typedef long long int lli;

lli HPcalc(lli bs, lli ev, lli iv, lli l){
	double div, sqrt_ev;
	div = l / 50;
	sqrt_ev = sqrt(ev) / 8;
	return (((iv + bs + sqrt_ev + 50) * div) + 10);
}

lli Scalc(lli bs, lli ev, lli iv, lli l){
	double div, sqrt_ev;
	div = l / 50;
	sqrt_ev = sqrt(ev) / 8;
	return (((iv + bs + sqrt_ev) * div) + 5);
}

lli main(){
	lli n, bs[4], ev[4], iv[4], l, i, j;
	char name[30];

	scanf("%lld", &n);

	for(i = 0; i < n; i++){
		scanf("%s\n%lld", name, &l);
		printf("%lld\n", l);
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &bs[0], &iv[0], &ev[0], &bs[1], &iv[1], &ev[1] , &bs[2],  &iv[2], &ev[2], &bs[3], &iv[3], &ev[3]);
		printf("Caso #%lld: %s nivel %lld\nHP %lld\nAT %lld\nDF %lld\nSP %lld\n", (i+1), name, l, HPcalc(bs[0], ev[0], iv[0], l), Scalc( bs[1], ev[1], iv[1], l), Scalc( bs[2], ev[2], iv[2], l), Scalc(bs[3], ev[3], iv[3], l));
	}
	return 0;
}