//Lukasavicus 1009

#include<iostream>
#include<stdio.h>
using namespace std;

main(){

	string nome;
	double base, comissao;
	double const taxa = 0.15;

	cin >> nome >> base >> comissao;

	printf("TOTAL = R$ %.2lf\n", base + (comissao * taxa));


}
