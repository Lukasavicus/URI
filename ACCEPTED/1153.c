//Lukasavicus 1153

#include <stdio.h>

int fat(int n){
  if(n == 0)
    return 1;
  return n * fat(n-1);
}

main(){
  
  int n;

  scanf("%d", &n);

  n = fat(n);

  printf("%d\n", n);

}