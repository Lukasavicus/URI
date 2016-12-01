//Lukasavicus 1156

#include <stdio.h>

main(){
  double s = 0;

  int const max = 39;
  int i;
  double exp = 1;

  for (i = 1; i < max; i+=2, exp *= 2)
    s += (double)((double)(i)/(double)(exp));

  printf ("%.2lf\n", s);

}