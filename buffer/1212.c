// Lukasavicus 1212

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char as[10], bs[10];
	int len_as, len_bs, min_len, i, carr, n_carrs, flag = 0;

	while(1){

		scanf("%s %s", &as, &bs);

		if(strcmp(as, "0\0") && strcmp(bs, "0\0"))
			return 0;


		len_as = strlen(as);
		len_bs = strlen(bs);

		min_len = (len_as > len_bs) ? len_bs : len_as;
		printf("%d %d %d\n", len_as, len_bs, min_len);
		for(i = 0, carr = 0, n_carrs; i < min_len; i++){
			carr = ((as[len_as-i] + bs[len_bs-i] + carr) > 10);
			n_carrs += carr;
		}
		if(n_carrs == 0)
			printf("No carry operation.\n");
		else if(n_carrs == 1)
			printf("%d carry operation.\n", n_carrs);
		else
			printf("%d carry operations.\n", n_carrs);

	}

	return 0;
}