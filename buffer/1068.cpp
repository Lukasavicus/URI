/* Lukasavicus - 1068 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <stack>
#include <iterator>

using namespace std;

int main(){
    
    stack<int> pars;
    char s[1001], c;
    int si = 0;
    int ans, eof;

    while(scanf("%c", &c) != EOF){
        ans = 1;
        if(c == '\n' || c == '\0'){
            s[si] = '\0';
            si = 0;
            for(int i = 0; i < strlen(s); ++i){
                if(s[i] == '(')
                    pars.push(1);
                if(s[i] == ')'){
                    if(pars.empty())
                        ans = 0;
                    else
                        pars.pop();
                }
            }
            ans = ans && (pars.size() == 0);
            if(ans)
                printf("correct\n");
            else
                printf("incorrect\n");
            while(!pars.empty())
                pars.pop();
        }
        else{
            s[si++] = c;
        }
    }

    return 0;
}