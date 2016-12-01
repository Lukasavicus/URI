//Lukasavicus 1973

#include <stdio.h>

int v[1123456];

main(){
  int n, i, c, num, max, sum;
  
  scanf("%d", &n);

  for(i = 1, sum = 0; i <= n; i++){
    scanf("%d", &v[i]);
    sum += v[i];
  }

  for(i = 1, c = 0, max = 1; i <= n && i > 0;){
    printf(">%d\n", i);

    if(i > max) max = i;

    num = v[i];

    //Atack!
    if(num > 0){
      v[i]--;
      c++;
    }

    if(num % 2 == 0)
      i--;
    else
      i++;

    if(i > max) max = i;

  }
  //printf("%d %d\n", max, min);
  printf("%d %d", max,  (sum - c) );

}