/* Lukasavicus - 1410 */

#include<stdio.h>

int main(){

	int n, m, aux;
	int sf,  //smaller foward
		sb1, //smaller back 1
		sb2; //smaller back 1

	while(1){
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		sf = 112345;
		sb1 = 112344;
		sb2 = 112345;
		for(int i = 0; i < n; i++){
			scanf("%d", &aux);
			if(aux < sf)
				sf = aux;
		}
		for(int i = 0; i < m; i++){
			scanf("%d", &aux);
			if(aux <= sb1){
				sb2 = sb1;
				sb1 = aux;
			}
			if(aux > sb1 && aux < sb2)
				sb2 = aux;
		}
		//printf("%d | %d - %d\n", sf, sb1, sb2);
		if(sf >= sb2)
			printf("N\n");
		else
			printf("Y\n");
	}

	return 0;
}