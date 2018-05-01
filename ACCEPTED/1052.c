// Lukasavicus 1052

#include <stdio.h>
#include <string.h>

main(){

	int mes;
	char resp[40];
	
	scanf("%d", &mes);

	switch(mes){
		case 1: strcpy(resp, "January\n"); break;
		case 2: strcpy(resp, "February\n"); break;
		case 3: strcpy(resp, "March\n"); break;
		case 4: strcpy(resp, "April\n"); break;
		case 5: strcpy(resp, "May\n"); break;
		case 6: strcpy(resp, "June\n"); break;
		case 7: strcpy(resp, "July\n"); break;
		case 8: strcpy(resp, "August\n"); break;
		case 9: strcpy(resp, "September\n"); break;
		case 10: strcpy(resp, "October\n"); break;
		case 11: strcpy(resp, "November\n"); break;
		case 12: strcpy(resp, "December\n"); break;
	}


	printf("%s", resp);

}