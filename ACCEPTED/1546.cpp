/* Lukasavicus - 1546 */

#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main() {
	
	int TC, cases, n;
	
    scanf("%d", &TC);
	while(TC--){
	    scanf("%d", &cases);
		while(cases--){
			scanf("%d", &n);
			switch(n){
				case 1: printf("Rolien\n"); break;
				case 2: printf("Naej\n"); break;
				case 3: printf("Elehcim\n"); break;
				case 4: printf("Odranoel\n"); break;
			}
		}
	}
	return 0;
}
