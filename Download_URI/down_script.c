#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#include  <stdio.h>
#include  <sys/types.h>
#include <sys/wait.h>

struct _Parameter{
	int min;
	int max;
	char lang;

}Parameter;

void int2str(char *s, const int n){

	int r = n;
	int size = strlen(s);
	int i = size - 1 ;

	while(r){
		s[i--] = (r % 10) + '0';
		r /= 10;
	}

}

int str2int(const char *s){
	int size = strlen(s);
	int i;
	int ans = 0;
	for(i = 0; i < size; i++){
		ans += pow(s[i], size-i);
	}
	return ans;
}


int check_helper(const int argc, const char **argv){
	int i;
	for(i = 1; i < argc; i++){
		if(strcmp(argv[i], "-h")){
			printf("URI Down Problems\n\n");
			printf("\t-m : min integer that defines the minumum value id to download\n\n");
			printf("\t-M : max integer that defines the maximum value id to download\n\n");
			printf("\t-l : lang char that defines the language of the problems to be download\n\n");
		}
	}
}

Parameter grab_parameters(const int argc, const char **argv){
	int min = 1001, max = 2795;
	char lang = 'p';
	int i;

	Parameter p;

	for(i = 1; i < argc; i++){
		if(strcmp(argv[i], "-m")){
			if((i+1) < argc){
				min = str2int(argv[i+1]);
			}
			else{
				printf("Error -m flag founded, but the value was not founded\n");
				break;
			}
		}
		if(strcmp(argv[i], "-M")){
			if((i+1) < argc){
				max = str2int(argv[i+1]);
			}
			else{
				printf("Error -M flag founded, but the value was not founded\n");
				break;
			}
		}
		if(strcmp(argv[i], "-l")){
			if((i+1) < argc){
				lang = (argv[i+1]);
			}
			else{
				printf("Error -l flag founded, but the value was not founded\n");
				break;
			}
		}
	}

	p.min = min;
	p.max = max;
	p.lang = lang;

	return p;

}

int main(const int argc, const char **argv){

	Parameter p;
	p = grab_parameters(argc, argv);
	
	int i;
	int min = 1363;
	int max = 2795;
	
	//min = int(argv[1]);
	//max = int(argv[2]);

	//Existem 1300 problemas ou seja o último é o 2301

	pid_t pid;

	//curl -o 1001.html https://www.urionlinejudge.com.br/repository/UOJ_1001.html

	char cmd[] = "curl";

	const char html[] = ".html";

	char number[] = "1000";

	char number_complete[] = "1000.html";

	const char url[] = "https://www.urionlinejudge.com.br/repository/UOJ_";

	char url_complete[] = "https://www.urionlinejudge.com.br/repository/UOJ_1000.html";

	for(i = min; i < max; i++){

		int2str(number, i);
		strcpy(number_complete, number);
		strcat(number_complete, html);

		strcpy(url_complete, url);
		strcat(url_complete, number_complete);

		//char *args[] = {cmd, "-s", "-o", number_complete, url_complete, NULL};
		char *args[] = {cmd, "-o", number_complete, url_complete, NULL};

		//printf("%s\n", number);

		printf(">%s<\n", url_complete);

		pid = fork();
		if(pid == 0)
			execvp(cmd, args);
		else
			wait(&pid);
	}

	return 0;
}