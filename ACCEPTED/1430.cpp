/* Lukasavicus - 1430 */

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main(){
    
    map<char, double> table;

    table['W'] = (1/1.0);
    table['H'] = (1/2.0);
    table['Q'] = (1/4.0);
    table['E'] = (1/8.0);
    table['S'] = (1/16.0);
    table['T'] = (1/32.0);
    table['X'] = (1/64.0);

    char c;

    double sum = 0;
    int qnt = 0;

    while(scanf("%c", &c) != EOF){
        if(c == '/'){
            if(sum == 1.0)
                qnt++;
            sum = 0;
        }
        if(c == '\n' || c == '\0'){
            printf("%d\n", qnt);
            qnt = 0;
        }
        else if(c == '*'){
            break;
        }
        else
            sum += table[c];
    }

    return 0;
}