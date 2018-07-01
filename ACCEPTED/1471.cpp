/* Lukasavicus - 1471 */

#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(){
  vector<int> v;
  int n, m, aux;
  while(scanf("%d %d", &n ,&m) != EOF){
      v = vector<int>(n);
      for(int i = 0; i < n; i++)
        v[i] = (i+1);
      for(int i = 0; i < m; i++){
        scanf("%d", &aux);
        v[(aux-1)] = 0;
      }
      if(n == m)  printf("*\n");
      else{
        for(int i = 0; i < v.size(); i++)
           if(v[i] != 0)
              printf("%d ", v[i]);
        printf("\n");
      v.clear();
    }
  }
  return 0;
}