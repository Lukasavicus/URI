/* Lukasavicus - 1259 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

typedef vector<int> vi;

int main(){	
	
	int d, n;
	vi even, odd;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &d);
		if (d % 2)
			odd.push_back(d);
		else
			even.push_back(d);
	}

	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());

	for(int i = 0; i < even.size(); i++)	printf("%d\n", even[i]);
	for(int i = odd.size()-1; i >= 0; i--)	printf("%d\n", odd[i]);

	return 0;
}