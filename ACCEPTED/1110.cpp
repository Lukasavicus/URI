/* Lukasavicus - 1110 */

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <deque>
#include <string>
#include <iterator>

using namespace std;

int main() {
	
	int n, c, aux, num;

	while(1){
		scanf("%d", &n);
		if(!n)
			break;

		deque<int> d;

		for(int i = 1; i <= n; i++)
			d.push_back(i);

		printf("Discarded cards: ");
		while(d.size() >= 2){
			printf("%d", d.front());
			d.pop_front();
			if(d.size() >= 2)
				printf(", ");
			d.push_back(d.front());
			d.pop_front();
		}
		printf("\nRemaining card: %d\n", d.front());
	}
	return 0;
}
