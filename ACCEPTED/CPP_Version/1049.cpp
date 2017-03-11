//Lukasavicus 1049

#include<iostream>
#include<stdio.h>
using namespace std;

main(){

	string opt1, opt2, opt3;

	cin >> opt1 >> opt2 >> opt3;

	if(opt1 == "vertebrado"){
		if(opt2 == "ave"){
			if(opt3 == "carnivoro")
				printf("aguia\n");
			else{
				printf("pomba\n");
			}
		}
		else{
			if(opt3 == "onivoro")
				printf("homem\n");
			else
				printf("vaca\n");
		}
		
	}
	else{
		if(opt2 == "inseto"){
			if(opt3 == "hematofago")
				printf("pulga\n");
			else
				printf("lagarta\n");
		}
		else{
			if(opt3 == "onivoro")
				printf("minhoca\n");
			else
				printf("sanguessuga\n");
		}
	}


}
