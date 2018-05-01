//Lukasavicus 1765

#include<stdio.h>

main(){
  int n, i, q;
  double a, b;

  do{
    scanf ("%d", &n);
    if(n == 0){
      break;
    }
    for(i = 0; i < n; i++){
      scanf ("%d %lf %lf", &q, &a, &b);
      printf ("Size #%d:\nIce Cream Used: %.2lf cm2\n", i+1, (((a+b)*5/2)*(double)(q)));
    }
    printf("\n");
  }while (n != 0);

}