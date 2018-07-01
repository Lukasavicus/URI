/* Lukasavicus - 2454 */

#include<stdio.h>
#include<vector>

using namespace std;

int main(){
  int p1, p2;
  scanf("%d %d", &p1, &p2);
  if(p1){
    if(!p2)
      printf("B\n");
    else
      printf("A\n");
  }
  else
    printf("C\n");
  return 0;
}