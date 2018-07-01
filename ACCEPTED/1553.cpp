/* Lukasavicus - 1553 */

#include<stdio.h>
#include<vector>

using namespace std;

int main(){
	
	int n, k, faq, aux;
	vector<int> v;

	while(1){
		scanf("%d %d", &n, &k);

		if(!n && !k)
			break;
        
        v = vector<int>(n);
		faq = 0;

		for(int i = 0; i < n; i++){
			scanf("%d", &aux);
			v[aux-1]++;
		}

		for(int i = 0; i < n; i++)
			if(v[i] >= k)
				faq++;

		printf("%d\n", faq);
		v.clear();
	}

	return 0;
}