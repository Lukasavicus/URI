#include <stdio.h>
#include <string.h>

typedef struct _problem{
	int id;
	int subject;
	int status;
}Problem;

void printfSubject(int subject){
	//switch(subject)
}

int scanfSubject(){
	//switch(subject)
	return 0;
}

void printfStatus(int status){
	//switch(status)	
}


int scanfStatus(){
	//switch(status)	
	return 0;
}

void printZero(Problem p[], int min, int max){
	int i;
	max = 2301;

	for(i = min; i < max; i++){
		printf("%d\t", p[i].id);
		p[i].subject = printTema();
		p[i].status = printStatus();
		printf("\n");
	}
}

void readData(Problem p[]){
	int i;
	max = 2301;

	for(i = min; i < max; i++){
		scanf("%d", &p[i].id);
		scanfSubject(&p[i].subject);
		scanfStatus(&p[i].status);
	}	
}

void main(/* int argc, char *argv[] */){
	Problem * problems;
	int qnt = 1254;

	problems = (Problem *) malloc(qnt * sizeof(Problem));

	

}