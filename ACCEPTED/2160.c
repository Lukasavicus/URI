//Lukasavicus 1

#include <stdio.h>

int main(){
    char c;
    int i = 0;

    while(1){
        scanf("%c", &c);
        if(c == '\n'){
            break;
        }
        else
            i +=1 ;
    }
    if(i <= 80)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}