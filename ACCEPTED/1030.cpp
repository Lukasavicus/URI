/* Lukasavicus - 1030 */

#include <stdio.h>

#include <iostream>     // std::cout
#include <numeric>      // std::iota
#include <vector>
#include <iterator>

using namespace std;

int main() {
	
	int TC,
		s,	// size
		j;  // jump

	vector<int> v;
	int i = 1;

    scanf("%d", &TC);

	while(TC--){
		scanf("%d %d", &s, &j);
		v = vector<int>(s);
		iota(std::begin(v), std::end(v), 1);
		int idx = 0;
		while(/*v.size() >= 1*/ v.size() > 1){
		    idx = (idx+(j-1))%v.size();
		    //printf("v[%d] = %d\n", idx, v[idx]);
			v.erase(v.begin()+idx);
		}
		printf("Case %d: %d\n", i++, v[0]);
		v.clear();
	}
	return 0;
}
