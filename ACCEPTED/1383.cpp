/* Lukasavicus - 1383 */

#include<stdio.h>

int main(){
	
	int TC, mtx[9][9], flag, vc[9], vr[9], vs[9], ntc;

	scanf("%d", &TC);
	ntc = 1;
	while(TC--){
		flag = 1;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				scanf("%d", &mtx[i][j]);
				if(mtx[i][j] > 9 || mtx[i][j] < 0)
					flag = 0;
			}
		}
		// check columns and rows
		for(int i = 0; i < 9; i++){
			for(int k = 0; k < 9; k++){
				vc[k] = 1;
				vr[k] = 1;
			}
			for(int j = 0; j < 9; j++){
				if(vr[mtx[i][j] - 1])
					vr[mtx[i][j] - 1] = 0;
				else
					flag = 0;
				if(vc[mtx[j][i] - 1])
					vc[mtx[j][i] - 1] = 0;
				else
					flag = 0;
			}
		}
		// check squares
		for(int i = 0; i < 9; i++){
			for(int k = 0; k < 9; k++)
				vs[k] = 1;
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					if(vs[mtx[(j+((i/3)*3))][(k+((i%3)*3))] -1])
						vs[mtx[(j+((i/3)*3))][(k+((i%3)*3))] -1] = 0;
					else
						flag = 0;
				}
			}
		}

		printf("Instancia %d\n", ntc++);
		if(flag)
			printf("SIM\n\n");
		else
			printf("NAO\n\n");
	}
	return 0;
}