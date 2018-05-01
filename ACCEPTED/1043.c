//Lukasavicus 1043

#include <stdio.h>

main(){
  double a, b ,c;

	scanf("%lf %lf %lf", &a, &b, &c);

	//printf("%d %d %d\n", ((a+b)>c) , ((a+c)>b) , ((c+b)>a));

  if(((a+b)>c) && ((a+c)>b) && ((c+b)>a))
    printf ("Perimetro = %.1lf\n", (a+b+c));
  else
    printf ("Area = %.1lf\n", (((a+b)*c)/2));

}