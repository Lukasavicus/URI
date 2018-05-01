// Lukasavicus 1864

# include <stdio.h>

void main (){
	
	const char phrase[] = {'L', 'I', 'F', 'E', ' ', 'I', 'S', ' ', 'N', 'O', 'T', ' ', 'A', ' ', 'P', 'R', 'O', 'B', 'L', 'E', 'M', ' ', 'T', 'O', ' ', 'B', 'E', ' ', 'S', 'O', 'L', 'V', 'E', 'D'};
	const int MAX = 34;
	
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		printf("%c", phrase[i]);
	printf("\n");
}

