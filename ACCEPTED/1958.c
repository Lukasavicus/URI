//Lukasavicus 1958

#include <stdio.h>

int main(){
    double d;

    scanf("%lf", &d);
    char resp[1123];

    sprintf(resp, "%.4E\n", d);

    if((d >= 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000) && (resp[0] != '-'))
        printf("+");
    printf("%.4E\n", d);

    return 0;
}