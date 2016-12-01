// Lukasavicus 1179

# include <stdio.h>

#define MAX 15

typedef struct _Queue{
  int h, t;
  int vec[MAX];
} Queue;


int main(){
	Queue par, impar;
	par.h = 0; par.t = 0;
	impar.h = 0; impar.t = 0;

	int n, i, j, k;

	for(i = 0; i < MAX; i++){
		scanf("%d", &n);
	    if(n % 2 == 0){
	      par.vec[par.h++] = n;
	    	if(par.h % 5 == 0)
			{
	    		for(par.t, k = 0; par.t < par.h; par.t++, k++)
				{
	          		printf("par[%d] = %d\n", k, par.vec[par.t]);
	      		}
	    	}
	    }
    	else
		{
			impar.vec[impar.h++] = n;
    		if(impar.h % 5 == 0)
			{
    			for(impar.t, k = 0; impar.t < impar.h; impar.t++, k++)
				{
          			printf("impar[%d] = %d\n", k, impar.vec[impar.t]);
      			}
    		}
  		}
	}
	
  	for(impar.t, k = 0; impar.t < impar.h; impar.t++, k++)
		printf("impar[%d] = %d\n", k, impar.vec[impar.t]);

	for(par.t, k = 0; par.t < par.h; par.t++, k++)
		printf("par[%d] = %d\n", k, par.vec[par.t]);

}
