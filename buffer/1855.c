//Lukasavicus 1855

#include<stdio.h>

main(){
  char c;
  int t = 0, f = 0, e = 0, l, co, i = 0, to, er  = 0;
  scanf("%d %d\n", &l, &co);
  
  to = l * co;
  for(i = 0; i < to; i++){
    scanf("%c", &c);
    //printf("-%c-\n", c);
    if(c == '*')
      t = 1;
    else if(c == '.')
      e = 1;
    else if(c == '<' || c == '>' || c == '^' || c == 'v')
      f = 1;
    else
      er = 1;
  }
  if(t != 0 && f != 0 && e !=0 && !er && co != l)
    printf("*\n");
  else
    printf("!\n");
 
}
