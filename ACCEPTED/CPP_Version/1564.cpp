//Lukasavicus 1564

#include<iostream>
#include<stdio.h>
using namespace std;

main(){

	int leitor;
	
	while(fscanf(stdin, "%d", &leitor) != EOF)
		if(leitor == 0)
			printf("vai ter copa!\n");
		else
			printf("vai ter duas!\n");

}
