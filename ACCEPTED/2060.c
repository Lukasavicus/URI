// Lukasavicus 2060

#include <stdio.h>

main(){
	
	int n, i, num, m2 = 0, m3 = 0, m4 = 0, m5 = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &num);
		if(num % 2 == 0)
			m2++;
		if(num % 3 == 0)
			m3++;
		if(num % 4 == 0)
			m4++;
		if(num % 5 == 0)
			m5++;
	}

	printf("%d Multiplo(s) de 2\n%d Multiplo(s) de 3\n%d Multiplo(s) de 4\n%d Multiplo(s) de 5\n", m2, m3 , m4, m5);	
}