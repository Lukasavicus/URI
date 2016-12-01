//Lukasavicus 1478

#include <stdio.h>

main(){
  int n, i, j, k;
  do{
    scanf("%d", &n);
    if(n == 0){
      break;
    }
    for(i = 0, k = 1; i < n; i++, k = i + 1){
      for(j = 0; j < n; j++){
        if(j == 0){
          if(k != 100)
            printf("% 3d", k);
          else
            printf("%d", k);
        }
        else
          printf("% 4d", k);
        if(j < i)
          k--;
        else
          k++;
      }
      printf ("\n");
    }
    printf ("\n");
  }while(n != 0);
}