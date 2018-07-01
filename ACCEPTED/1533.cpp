/* Lukasavicus - 1533 */

#include<stdio.h>
#include<vector>

using namespace std;

int main(){
  int n, b1, b2, aux, ib1, ib2;
  while(1){
    b1 = -1;
    b2 = -2;
    ib1 = 1;
    ib2 = 1;
    scanf ("%d", &n);
    if(!n)
      return 0;
    for(int i = 0; i < n; i++){
      scanf("%d", &aux);
      if(aux > b1){
        ib2 = ib1;
        ib1 = (i+1);
        b2 = b1;
        b1 = aux;
      }
      if(aux > b2 && aux < b1){
        b2 = aux;
        ib2 = (i+1);
      }
    }
    printf("%d\n", ib2);
    //printf("%d<\n", b2);
  }
  return 0;
}