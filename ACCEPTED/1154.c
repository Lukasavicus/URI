//Lukasavicus 1154
 
#include <stdio.h>
 
main(){
 
    int n = 0, num; 
    double sum = 0;
     
    while(1){
        scanf("%d", &num);
        if(num > 0){
            n++;
            sum += num;
        }
        else{
            printf("%.2lf\n", (double)(sum/n));
            return;
        }
    }
     
}