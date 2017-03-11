	//Lukasavicus 1021

	#include<iostream>
	#include<stdio.h>


	using namespace std;

	main(){

		double value;
		int aux;

		cin >> value;

		//value += 0.009;

		aux = value;

		printf("NOTAS:\n");
		printf("%d nota(s) de R$ 100.00\n", aux / 100);	
		aux = value / 100;
		value = value - aux * 100;
		aux = value;
		printf("%d nota(s) de R$ 50.00\n", aux / 50);
		aux = value / 50;
		value = value - aux * 50;
		aux = value;
		printf("%d nota(s) de R$ 20.00\n", aux / 20);	
		aux = value / 20;
		value = value - aux * 20;
		aux = value;
		printf("%d nota(s) de R$ 10.00\n", aux / 10);
		aux = value / 10;
		value = value - aux * 10;
		aux = value;
		printf("%d nota(s) de R$ 5.00\n", aux / 5);	
		aux = value / 5;
		value = value - aux * 5;
		aux = value;
		printf("%d nota(s) de R$ 2.00\n", aux / 2);
		aux = value / 2;
		value = value - aux * 2;
		aux = value;
		
		value = value * 100;

		aux = value;

		printf("MOEDAS:\n");
		printf("%d moeda(s) de R$ 1.00\n", aux / 100);
		aux = value / 100;
		value = value - aux * 100;
		aux = value;
		printf("%d moeda(s) de R$ 0.50\n", aux / 50);
		aux = value / 50;
		value = value - aux * 50;
		aux = value;
		printf("%d moeda(s) de R$ 0.25\n", aux / 25);
		aux = value / 25;
		value = value - aux * 25;
		aux = value;
		printf("%d moeda(s) de R$ 0.10\n", aux / 10);
		aux = value / 10;
		value = value - aux * 10;
		aux = value;
		printf("%d moeda(s) de R$ 0.05\n", aux / 5);
		aux = value / 5;
		value = value - aux * 5;
		aux = value;
		//printf("%d %.4f\n", aux, value);
		printf("%d moeda(s) de R$ 0.01\n", aux / 1);

	}
