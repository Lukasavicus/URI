/* Lukasavicus - 1171 */

#include <stdio.h>

#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
	
	int TC, n;
	const int size = 2001;
	vector<int> v(size);

    scanf("%d", &TC);

	while(TC--){
		scanf("%d", &n);
		v[n]++;
	}
	for(int i = 0; i < size; i++){
		if(v[i])
			printf("%d aparece %d vez(es)\n", i, v[i]);
	}
	return 0;
}
