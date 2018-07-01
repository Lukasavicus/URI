/* Lukasavicus - 1091 */
#include<stdio.h>
int main(){
  int TC, x0, y0, x, y;
  char ns, we;
  while(1){
    scanf("%d", &TC);
    if(! TC)
      return 0;
    scanf("%d %d", &x0, &y0);
    while(TC--){
      scanf ("%d %d", &x, &y);
      x -= x0;
      y -= y0;
      if(x == 0 || y == 0)  printf("divisa\n");
      else{
        we = (x > 0) ? 'E' : 'O';
        ns = (y > 0) ? 'N' : 'S';
        printf("%c%c\n", ns, we);
      }
    }
  }
  return 0;
}