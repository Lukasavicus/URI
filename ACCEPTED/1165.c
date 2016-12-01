//Lukasavicus 1165
 
#include <stdio.h>
#include <math.h>
 
main(){
 
    int n, q, i, j;
 
    scanf("%d", &q);
        for(i = 0; i < q; i++){
            scanf("%d", &n);
 
            for(j = 2; j < n; j++)
                if(n % j == 0)
                    break;
 
            if((j != n) || (n == 0) || (n == 1))
                printf("%d nao eh primo\n", n);
            else
                printf("%d eh primo\n", n);
        }
}