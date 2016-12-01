//Lukasavicus 1796

#include <stdio.h>


main(){
  int n, i, s = 0, v;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
  	scanf("%d", &v);
  	if(v == 1)
  		s++;
  }
  n = (n % 2 == 0) ? (n/2) : (n/2)+1;
  (s >= n) ? printf("N\n") : printf("Y\n");
}