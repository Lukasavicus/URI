// Lukasavicus 1072

#include <stdio.h>

main(){

	int i, qnt, in = 0, out = 0, num;
	
	scanf("%d", &qnt);

	for(i = 0; i < qnt; i++){
		scanf("%d", &num);
		if(num >= 10 && num <= 20)
			in++;
		else
			out++;
	}

	printf("%d in\n%d out\n", in, out);

}