//Lukasavicus 1160

#include<iostream>
#include<stdio.h>
using namespace std;

main(){

	int t, pa, pb;
	int k = 0;
	double g1, g2;

	cin >> t;

	for(int i = 0; i < t; i++, k = 0){
		cin >> pa >> pb >> g1 >> g2;
		for(int j = 1; pa <= pb && k <= 100; k++, pa = pa + (pa * (g1/100)), pb = pb + (pb * (g2/100))){ /*printf("%d %d\n", pa, pb);*/}
			if(k <= 100)
				printf("%d anos.\n", k);
			else
				printf("Mais de 1 seculo.\n");
	}

}
