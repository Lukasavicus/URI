//Lukasavicus 2139

#include<stdio.h>

int main(){
    const int m[] = {360, 329, 300, 269, 239, 208, 178, 147, 116, 86, 55, 25};
    int diff, mes, dia;
    while(scanf("%d %d", &mes, &dia) != EOF){
        if(mes == 12){
            if(dia >= 26)
                printf("Ja passou!\n");
            if(dia == 25)
                printf("E natal!\n");
            if(dia == 24)
                printf("E vespera de natal!\n");
            if(dia <= 23)
                printf("Faltam %d dias para o natal!\n", 25 - dia);
        }
        else{
            printf("Faltam %d dias para o natal!\n", m[mes-1]-dia);
        }
    }
    return 0;
}