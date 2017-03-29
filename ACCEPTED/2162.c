//Lukasavicus 2162

#include <stdio.h>

int main(){

    int TC, n[100], nlg = 1, i, p;

    scanf("%d", &TC);
    for(i = 0; i < TC; i++)
        scanf("%d", &n[i]);
    
    if(TC == 1){
        printf("1\n");
    }
    else{
        if(n[0] == n[1]){
            printf("0\n");
        }
        else{
            p = n[0] > n[1];
            for(i = 2; i < TC; i++){
                if((p && !(n[i-1] < n[i])) || (!p && !(n[i-1] > n[i])))
                    nlg = 0;
                p = !p;
            }
            printf("%d\n", nlg);
        }
    }

    return 0;
}