//Lukasavicus 1161

#include <stdio.h>
#include <stdlib.h>

long long int fat(int n){
  if(n == 0)
    return 1;
  else
    return n * fat(n-1);
}

//long long int v[]= {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

main(){
  long long int a, b, c;
  while(scanf("%d %d", &a, &b) != EOF){
    c = fat(a) + fat(b);
	printf("%lld\n", c);
  }
}