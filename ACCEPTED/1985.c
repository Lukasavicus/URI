//Lukasavicus 1985

#include <stdio.h>

main(){
  int n, i, op, qnt;
  double sum = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d %d", &op, &qnt);
    switch(op){
      case 1001:
        sum += (1.5 * qnt);
        break;
      case 1002:
        sum += (2.5 * qnt);
        break;
      case 1003:
        sum += (3.5 * qnt);
        break;
      case 1004:
        sum += (4.5 * qnt);
        break;
      case 1005:
        sum += (5.5 * qnt);
        break;
    }
  }
  printf("%.2lf\n", sum);
}