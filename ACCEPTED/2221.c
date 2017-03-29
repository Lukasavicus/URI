//Lukasavicus 2221

#include <stdio.h>

int main(){

	int TC, b, Ad, Dd, Ld, Ag, Dg, Lg, d, g;

	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d %d %d %d %d %d", &b, &Ad, &Dd, &Ld, &Ag, &Dg, &Lg);
		d = ((Ad + Dd)/2)+( ((Ld+1)%2) * b);
		g = ((Ag + Dg)/2)+( ((Lg+1)%2) * b);
		if(d > g)
			printf("Dabriel\n");
		else if(d == g)
			printf("Empate\n");
		else
			printf("Guarte\n");
	}

    return 0;
}