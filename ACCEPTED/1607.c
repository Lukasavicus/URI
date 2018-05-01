//Lukasavicus 1607

#include <stdio.h>
#include <string.h>
#define MAX 11234

int diffabs(int a, int b){
  return (a > b ) ? (26 - (a - b)) : (b - a);
}

void main(){
  int n, i, j, l;
  long long diff;
  char s1[MAX], s2[MAX];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%s %s", s1, s2);
    l = strlen(s1);
    for(diff = 0, j = 0; j < l; j++){
      diff += diffabs(s1[j], s2[j]);
    }
    printf("%lld\n", diff);
  }

}