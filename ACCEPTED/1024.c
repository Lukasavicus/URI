// Lukasavicus 1024

#include<stdio.h>
#include<string.h>

int main(){
  int TC, size, i, j, aux;
  char string[1123],  caux;

  scanf("%d", &TC);
  scanf("%c", &caux);
  while(TC--){
    i = 0;
    while (1){
      if (scanf("%c", &caux) == EOF || caux == '\n')
        break;
      string[i++] = caux;
    }
    //printf("LIDO %d\n", TC);

    string[i] = '\0';
    size = strlen(string)-1;
    
    for(i = 0, j = size; i < j; i++, j--){
      //printf ("%d %d %c %c\n", i , j, string[i], string[j]);
      if((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')){
        string[i] += 3;
      }
      if((string[j] >= 'A' && string[j] <= 'Z') || (string[j] >= 'a' && string[j] <= 'z')){
        string[j] += 3;
      }
      
      aux = string[i]-1;
      string[i] = string[j];
      string[j] = aux;
    }

    if(size % 2 == 0){
      j = size/2;
      if((string[j] >= 'A' && string[j] <= 'Z') || (string[j] >= 'a' && string[j] <= 'z'))
        string[j] += 2;
      else
        string[j] -= 1;
    }

    //printf("%d\n", TC);
    
    printf ("%s\n", string);
  }
  

  return 0;
}
//Texto #3
//3# rvzgV
//3# oswdV