/* Lukasavicus - 1609 */

#include <stdio.h>
#include <map>

using namespace std;

typedef map<int, int> mii;
typedef pair<int, int> pii;

int main(){

	const int size = 10001;
	int TC, n, i, s, aux;

	mii m;
	mii::iterator it;
	it = m.begin();
	
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			m.insert(it, pii(aux, 1));
		}
		printf("%d\n", m.size());
		m.clear();
	}
	return 0;
}