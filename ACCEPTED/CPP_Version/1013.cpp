//Lukasavicus 1013

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

main(){

	int a, b, c, aux1, aux2, intermed;
	cin >> a >> b >> c;

	aux1 = (a + b + abs(a-b))/2;
	aux2 = (c + aux1 + abs(c-aux1))/2;

	printf("%d eh o maior\n", aux2);


}
