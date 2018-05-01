//Lukasavicus 1010

#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct _peca{

	int cod, num;
	float valor;
}Peca;

	istream & operator >> (istream &ref_io, Peca &ref_peca){

	ref_io >> ref_peca.cod;
	ref_io >> ref_peca.num;
	ref_io >> ref_peca.valor;

	return ref_io;
}

main(){

	Peca p1, p2;

	cin >> p1 >> p2;



	printf("VALOR A PAGAR: R$ %.2f\n", (p1.num * p1.valor) + (p2.num * p2.valor));


}
