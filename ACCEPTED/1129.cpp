/* Lukasavicus - 1129 */

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string ans;
	int TC, a, b, c, d, e;
	while(1){
		scanf ("%d", &TC);
		if(!TC)
		    return 0;
		while(TC--){
			scanf ("%d %d %d %d %d", &a, &b, &c, &d, &e);
			ans = "";
			ans += (a <= 127) ? "A" : "";
			ans += (b <= 127) ? "B" : "";
			ans += (c <= 127) ? "C" : "";
			ans += (d <= 127) ? "D" : "";
			ans += (e <= 127) ? "E" : "";

			if(ans.length() == 1)
				cout << ans << "\n";
			else
				printf("*\n");
		}
	}

	return 0;
}