//Lukasavicus 2143

#include <stdio.h>

int main(){

    int n, m, TC = 1;

    while(1){
        scanf("%d", &TC);
        m = TC;
        while(m--){
            scanf("%d", &n);
            if(n%2)
                printf("%d\n", (n*2)-1);
            else
                printf("%d\n", (n*2)-2);
        }
        if(!TC)
            break;
    }
    return 0;
}