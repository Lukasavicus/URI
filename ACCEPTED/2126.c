//Lukasavicus 2126

#include<stdio.h>
#include<string.h>

void cmp(const char * s1, const char * s2, int * pos, int * qtd){
    int size1, size2;
    size1 = strlen(s1);
    size2 = strlen(s2);

    int i, j, sizediff = size1 - size2;
    for(i = 0, *pos = 0, *qtd = 0; i <= sizediff; i++){
        for(j = 0; j < size2; j++){
            if(s1[i+j] != s2[j])
                break;
        }
        if((j == size2) && ((*pos) <= i)){
            *pos = i;
            *qtd += 1;
        }
    }    
}

int main(){
    char s1[12], s2[34];
    int TC = 1, pos = 0, qtd = 0;

    while(scanf("%s", s1) != EOF){
        scanf("%s", s2);
        cmp(s2, s1, &pos, &qtd);
        printf("Caso #%d:\n", TC++);
        if(qtd)
            printf("Qtd.Subsequencias: %d\nPos: %d", qtd, pos+1);
        else
            printf("Nao existe subsequencia");
        printf("\n\n");
    }
    return 0;
}