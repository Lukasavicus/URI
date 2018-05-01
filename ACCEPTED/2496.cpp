/* Lukasavicus - 2496 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

typedef vector<int> vi;

int main(){	
	
	int TC, letters, wrong_pos;
	char s[27];
	int size, i;

	scanf("%d", &TC);

	while(TC--){
		scanf("%d", &letters);
		scanf("%s", s);
		size = strlen(s);

		for(i = 0, wrong_pos = 0; i < size; i++)
			wrong_pos += ((s[i]-'A') != i);
		if(wrong_pos <= 2)
			printf("There are the chance.\n");
		else
			printf("There aren't the chance.\n");
	}

	return 0;
}