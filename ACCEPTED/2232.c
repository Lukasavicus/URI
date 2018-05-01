// lukasavicus 2172

#include <stdio.h>
#include <math.h>

int main(){
    int n, TC;

    scanf("%d", &TC);

    while(TC--){
        scanf("%d", &n);
        printf("%.0lf\n", (pow(2,n))-1);
    }
    return 0;
}