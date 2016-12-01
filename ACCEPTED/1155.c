//Lukasavicus 1155

#include <stdio.h>

main(){
  double s = 0;

  int const max = 100;
  int i;

  for (i = 1; i <= max; i++)
    s += (double)(1/(double)(i));

  printf ("%.2lf\n", s);

}