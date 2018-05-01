//Lukasavicus 1929

#include <stdio.h>

int isTri(int a, int b, int c){
  return ((a+b > c) && a < c && b < c);
}

main(){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  (
    isTri(a, b, c) || isTri(a, b, d) || isTri(a, c, b) || isTri(a, c, d) || isTri(a, d, b) || isTri(a, d, c) ||
                                        isTri(b, c, a) || isTri(b, c, d) || isTri(b, d, a) || isTri(b, d, c) ||
                                                                            isTri(c, d, a) || isTri(c, d, b)
  ) 
  ? printf("S\n") : printf("N\n");
}