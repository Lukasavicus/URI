//Lukasavicus 1131

#include <stdio.h>

main(){
  int n1, n2;
  int inter = 0, gremio = 0, empate = 0;
  int opt;

  do{
    
    scanf ("%d", &n1);
    
    scanf ("%d", &n2);

    printf ("Novo grenal (1-sim 2-nao)\n");
    scanf("%d", &opt);

    if(n1 > n2)
      inter++;
    else if (n2 > n1)
      gremio++;
    else
      empate++;

    if(opt == 2){
      printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n", (inter + gremio + empate), inter, gremio, empate);
      if(inter > gremio )//&& empate < (inter + gremio)
        printf ("Inter venceu mais\n");
      else if ( gremio > inter)
        printf ("Gremio venceu mais\n");
      else
        printf ("Nao houve vencedor\n");

      break;
    }

  }while(1);

}