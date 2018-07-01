/* Lukasavicus - 1250 */
#include <iostream>
#include <string>

using namespace std;

int main(){
    int TC, n, v[50], i, hits;
    char s[51];
    scanf("%d", &TC);
    while(TC--){
        hits = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        scanf("%s", s);
        for(int i = 0; i < n; i++){
            if((s[i] == 'S' && v[i] <= 2) || (s[i] == 'J' && v[i] > 2))
                hits++;
        }
        printf("%d\n", hits);
    }
    return 0;
}