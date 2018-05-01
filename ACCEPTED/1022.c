// Lukasavicus 1022

#include <stdio.h>
#include <stdlib.h>


int mdc(int a, int b){
   int aux;

   if(a < 0){ a = -a; }
   if(b < 0){ b = -b; }
   if(a < b){ aux = a; a = b; b = aux; }

   if(!b)   return a;
   else     return mdc(b, (a % b));
}

int main () {
   int TC;
   scanf("%d", &TC);

   int N1, D1, N2, D2;
   char op;

   int NR, DR;
   int n_mdc;


   while(TC--){
      scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
      switch(op){
         case '+':
            NR = N1*D2 + N2*D1;
            DR = D1*D2;
         break;
         case '-':
            NR = N1*D2 - N2*D1;
            DR = D1*D2;
         break;
         case '*':
            NR = N1*N2;
            DR = D1*D2;
         break;
         case '/':
            NR = N1*D2;
            DR = N2*D1;
         break;
      }
      printf("%d/%d", NR, DR);
      n_mdc = mdc(NR,DR);
      printf(" = %d/%d\n", NR/n_mdc, DR/n_mdc);
   }
   return(0);
}