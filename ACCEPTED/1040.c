//Lukasavicus 1040

#include<stdio.h>

main (){

  double n1, n2, n3, n4, exame, avg;

  scanf ("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

  avg = ((n1*2) + (n2*3) + (n3*4) + (n4*1)) / 10;

  printf("Media: %.1lf\n", avg);

  if(avg > 6){
    printf ("Aluno aprovado.\n");
    return;
  }
  else if (avg < 5){
    printf ("Aluno reprovado.\n");
    return;
  }
  else {
    printf ("Aluno em exame.\n");
    scanf("%lf", &exame);
    printf("Nota do exame: %.1lf\n", exame);
    if(exame >= 5)
      printf ("Aluno aprovado.\n");
    else
      printf ("Aluno reprovado.\n");
    printf("Media final: %.1lf\n", ((avg+exame)/2));
  }

}