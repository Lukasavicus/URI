//Lukasavicus 1557

#include <stdio.h>
#include <math.h>

int llog10(int n){
  int r = 0;
  n /= 10;
  while(n != 0){
    n /= 10;
    r++;
  }
  return r;
}

void printSpace(int t, int k){
  int i, n, m;
  m = log10(k);
  n = t;
  n++;
  n -= m;
  //printf("-%d-\n", n);
  for(i = 0; i < n; i++)
    printf(" ");
}



main(){
  int n, i, j, k, l;
  do{
    scanf("%d", &n);
    l = llog10((int)(pow(2,(n-1)*2)));
    //printf("-%d-\n", l);
    if(n == 0){
      break;
    }
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){

        k = (int)(pow(2,(i+j)));

        if(j == 0){
          printSpace(l-1, k);
        }
        else{
          printSpace(l, k);
        }

        printf("%d", k);
      }
      printf ("\n");
    }
    printf ("\n");
  }while(n != 0);
}