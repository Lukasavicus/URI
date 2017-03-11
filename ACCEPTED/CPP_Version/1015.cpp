//Lukasavicus 1015

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef struct {
	int x, y;

}Ponto;

istream & operator >> (istream &entry, Ponto &p){

	entry >> p.x;
	entry >> p.y;

	return entry;

}

main(){

	Ponto p1, p2;

	cin >> p1 >> p2;

	printf("%.4f\n", sqrt((pow((p1.x-p2.x), 2) + (pow((p1.y - p2.y), 2)))));


}
