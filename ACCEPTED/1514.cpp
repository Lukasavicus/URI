/* Lukasavicus - 1514 */
# include<stdio.h>

int main(){
	int mtx[100][100], v[100], aux, n, m;
    int cols_1, cols_n, rows_1, rows_n; //Flags
	while(1){
		scanf("%d %d", &n, &m);
		if(!n && !m)
			return 0;
        cols_1 = 1;
        cols_n = 1;
        rows_1 = 1;
        rows_n = 1;
		for(int i = 0; i < n; i++){
            int sum = 0;
			for(int j = 0; j < m; j++){
				scanf("%d", &mtx[i][j]);
                sum += mtx[i][j];
            }
            rows_1 = rows_1 && (sum > 0);
            rows_n = rows_n && (sum < m);
        }
        for(int i = 0; i < m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += mtx[j][i];
            }
            cols_1 = cols_1 && (sum > 0);
            cols_n = cols_n && (sum < n);
        }
        printf("%d\n", (rows_1 + rows_n + cols_1 + cols_n));
	}
	
	return 0;
}