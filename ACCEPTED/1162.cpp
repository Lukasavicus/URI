/* Lukasavicus - 1162 */

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int bubble_changes(vector<int>& v, int size){
	int ans = 0, aux;

	for(int i = 0; i < size; i++){
		for(int j = i; j < size; j++){
			if(v[i] > v[j]){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				ans++;
			}
		}
	}

	return ans;
}

int main() {
	
	int TC, m, aux, ans;
	vector<int> v(50);

	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
			scanf("%d", &v[i]);

		ans = bubble_changes(v, m);
		printf("Optimal train swapping takes %d swaps.\n", ans);
		v.clear();
	}
	return 0;
}
