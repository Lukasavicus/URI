#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include  <stdio.h>
#include  <sys/types.h>
#include <sys/wait.h>

void int2str(char *s, const int n){

	int r = n;
	int size = strlen(s);
	int i = size - 1 ;

	while(r){
		s[i--] = (r % 10) + '0';
		r /= 10;
	}

}

int main(){

	int i;
	const int min = 2000;
	const int max = 2255;

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