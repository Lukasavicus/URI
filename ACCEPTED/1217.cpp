/* Lukasavicus - 1217 */

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

	int TC, ntc = 0, kg, t_kg = 0;
	double prc, t_prc = 0;
	string s;

	scanf("%d", &TC);
	while(TC--){
		scanf("%lf\n", &prc);
		t_prc += prc;
		getline(cin, s);
		kg = 1;
		for(int i = 0; i < s.length(); i++)
			if(s[i] == ' ')
				kg++;
		t_kg += kg;
		printf("day %d: %d kg\n", ++ntc, kg);
	}
	printf("%.2lf kg by day\n", (t_kg/double(ntc)));
	printf("R$ %.2lf by day\n", (t_prc/double(ntc)));
	return 0;
}