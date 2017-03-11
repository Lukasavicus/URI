// lukasavicus 2176

#include <stdio.h>
#include <string.h>

int main(){
    int  n_ones, i, len;
    char s[102];

        scanf("%s", s);
        len = strlen(s);
        for(i = 0, n_ones = 0; i < len; i++)
            n_ones += (s[i]-'0');

        printf("%s", s);
        if(n_ones % 2)
            printf("1\n");
        else
            printf("0\n");

        return 0;
}