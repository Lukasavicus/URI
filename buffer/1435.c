//Lukasavicus 1435

#include <stdio.h>

main(){

  int n, half, i, j, aux, num;

  scanf("%d", &n);

  if(n % 2 == 0)
    half = n /2;
  else
    half = n /2 + 1;

  for(i = 1, num = 1; i <= n; i++){


    printf("%d %d %d\n", i, num, half);

    for(j = 1; j <= num; j++){
      printf("(%d ", j);
    }

    aux = (n - (num * 2));

    for(j = 1; j < aux; j++){
      printf("{%d ", n);
    }

    for(j = num; j > 0; j--){
      printf("[%d ", j);
    }

    if(i <= half)
      num++;
    else
      num--;

    printf("\n");
  }

}

/*
main(){
  int n, i, j, k;
  do{
    scanf("%d", &n);
    if(n == 0){
      break;
    }
    for(i = 0, k = 1; i < n; i++, k = i + 1){
      for(j = 0; j < n; j++){
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
*/

/*

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

*/