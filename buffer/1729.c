/* Lukasavicus 1729*/

#include <stdio.h>
#include <string.h>

void strrepchr(char *s, char look, char replace){
	int i, size = strlen(s);
	for(i = 0; i < size; i++)
		if(s[i] == look)
			s[i] = replace;
}

int main(){

	int qnt, n[20], h, m, s, totsec, i = 0, j;
	double mean[20], d;
	char str[8], str2[8];

	scanf("%d %lf", &qnt, &d);
	while(scanf("%d", &n[i]) != EOF){
		for(j = 0, totsec = 0; j < qnt ; j++){
			scanf("%s", str);
			h = (str[0] - '0');
			m = ((str[2] - '0') * 10) + ((str[3] - '0') * 1);
			s = ((str[5] - '0') * 10) + ((str[6] - '0') * 1);
			totsec += (h*3600+m*60+s);
		}
		if(str[0] == '-')
			mean[i] = -1;
		else
			mean[i] = totsec / d;
		i++;
	}

	for(i = 0; i < qnt; i++){
		printf("% 3d: ", n[i]);
		if(mean[i] == -1)
			printf("-\n");
		else{
			sprintf(str2 ,"%.2lf", mean[i]);
			strrepchr(str2, '.', ':');
			printf(" %s min/km\n", str2);
		}
	}

	return 0;
}