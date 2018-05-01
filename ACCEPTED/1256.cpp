/* Lukasavicus - 1256 */

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
	
	int TC, m, c, aux;

	scanf("%d", &TC);
	while(TC--){

		vector<vector<int>> hash_table(200);

		scanf("%d %d", &m, &c);

		for (int i = 0; i < c; i++){
			scanf("%d", &aux);
			hash_table[(aux % m)].push_back(aux);
		}

		for (int i = 0; i < m; i++){
			printf("%d -> ", i);
			for (int j = 0; j < hash_table[i].size(); j++){
				printf("%d -> ", hash_table[i][j]);
			}
			printf("\\\n");
		}
		if(TC)
			printf("\n");

		for(int i = 0; i < m; i++)
		    hash_table[i].erase(hash_table[i].begin(), hash_table[i].end());
	}
	return 0;
}
