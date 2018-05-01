//Lukasavicus 1160

#include<stdio.h>

main(){

	int t, pa, pb;
	int k = 0;
	double g1, g2;

	int i, j;

	//cin >> t;
	scanf("%d", &t);

	for(i = 0; i < t; i++, k = 0){
		//cin >> pa >> pb >> g1 >> g2;
		scanf("%d %d %lf %lf", &pa, &pb, &g1, &g2);
		for(j = 1; pa <= pb && k <= 100; k++, pa = pa + (pa * (g1/100)), pb = pb + (pb * (g2/100))){ /*printf("%d %d\n", pa, pb);*/}
			if(k <= 100)
				printf("%d anos.\n", k);
			else
				printf("Mais de 1 seculo.\n");
	}

}
