//Lukasavicus 1151


# include <stdio.h>

main(){
  int n1 = 0, n2 = 1, i, n, TAM;

  scanf("%d", &n);

  TAM = (n+1)/2;

  for(i = 0; i < TAM; i++){
    printf("%d", n1);
    if(!(n % 2 != 0 && (i+1) == TAM)){
      printf(" %d", n2);
      if((i+1) != TAM)
        printf(" ");
    }
    n1 += n2;
    n2 += n1;
  }
  printf("\n");

}