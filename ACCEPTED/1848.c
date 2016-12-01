//Lukasavicus 1848

#include<stdio.h>
#include<string.h>

main(){
  int g = 0, i;
  int v[] = {0, 0, 0};
  char grito[5];
  while (g < 3){
    scanf ("%s", grito);
    if(strcmp("caw", grito) == 0){
      g++;
      scanf("%s", grito);
    }
    else{
      if(grito[0] == '*')
        v[g] += 4;
      if(grito[1] == '*')
        v[g] += 2;
      if(grito[2] == '*')
        v[g] += 1;
    }
  }
  for(i = 0; i < 3; i++)
    printf("%d\n", v[i]);
}
