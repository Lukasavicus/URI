//Lukasavicus 1045

#include <stdio.h>

main(){

  double a, b, c, aux, r;
  scanf("%lf %lf %lf", &a, &b, &c);
 
  if(a < b){
    aux = a;  a = b;  b = aux;
  }

  if(b < c){
    aux = b;  b = c;  c = aux;
  }

  if(a < b){
    aux = a;  a = b;  b = aux;
  }

  if(a >= b + c){
    printf("NAO FORMA TRIANGULO\n");
    return;
  }

  r = (a*a) - ((b*b)+(c*c));

  if(r == 0)
    printf("TRIANGULO RETANGULO\n");
  else if( r > 0)
    printf("TRIANGULO OBTUSANGULO\n");
  else
    printf("TRIANGULO ACUTANGULO\n");

  if(a == b && b == c)
    printf("TRIANGULO EQUILATERO\n");
  else if(!(a != b && b != c && a != c))
    printf("TRIANGULO ISOSCELES\n");

}
