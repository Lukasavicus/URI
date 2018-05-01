//Lukasavicus 1049

#include <stdio.h>
#include <string.h>

main(){

	char opt1[40], opt2[40], opt3[40];
	
	scanf("%s", opt1);
	scanf("%s", opt2);
	scanf("%s", opt3);

	if(strcmp(opt1,"vertebrado") == 0){ //opt1 == "vertebrado"
		if(strcmp(opt2, "ave") == 0){//opt2 == "ave")
			if(strcmp(opt3, "carnivoro") == 0)//opt3 == "carnivoro"
				printf("aguia\n");
			else{
				printf("pomba\n");
			}
		}
		else{
			if(strcmp(opt3, "onivoro") == 0)//opt3 == "onivoro"
				printf("homem\n");
			else
				printf("vaca\n");
		}
		
	}
	else{
		if(strcmp(opt2, "inseto") == 0){//opt2 == "inseto")
			if(strcmp(opt3, "hematofago") == 0)//opt3 == "hematofago"
				printf("pulga\n");
			else
				printf("lagarta\n");
		}
		else{
			if(strcmp(opt3, "onivoro") == 0)//opt3 == "onivoro"
				printf("minhoca\n");
			else
				printf("sanguessuga\n");
		}
	}


}
