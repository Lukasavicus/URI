//Lukasavicus 1042

#include <stdio.h>

main(){
  
  int n1, n2, n3;
  int t1, t2, t3, aux;

  scanf ("%d %d %d", &n1, &n2, &n3);

  t1 = n1;
  t2 = n2;
  t3 = n3;

  if(t3 < t2){
    aux = t2;
    t2 = t3;
    t3 = aux;
  }

  if(t2 < t1){
    aux = t2;
    t2 = t1;
    t1 = aux;
  }

  if(t3 < t2){
    aux = t2;
    t2 = t3;
    t3 = aux;
  }

  printf ("%d\n%d\n%d\n\n%d\n%d\n%d\n", t1, t2, t3, n1, n2, n3);

}