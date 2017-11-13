/* Lukasavicus 2682 */

#include <stdio.h>

int main(){
	int x = -1, y, err = 0;
	while(scanf("%d", &y) != EOF){
		if(!err && x > y)
			err = x;
		x = y;
	}
	if(err)
		printf("%d\n", err+1);
	else
		printf("%d\n", y+1);
	return 0;
}