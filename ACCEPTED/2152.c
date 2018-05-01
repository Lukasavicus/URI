//Lukasavicus 2152

#include <stdio.h>

int main(){
    int TC, h, m, oc;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d %d", &h, &m, &oc);
        printf("%02d:%02d - ", h, m);
        if(oc)
            printf("A porta abriu!\n");
        else
            printf("A porta fechou!\n");
    }
    return 0;
}