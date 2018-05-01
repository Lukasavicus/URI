/* Lukasavicus - 2136 */

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <iterator>

using namespace std;

int main(){
    
    set<string> names;
    string name, ans, first;
    set<string>::iterator itss;
    int max = 0;

    while(1){
        cin >> name;
        if(name == "FIM")
            break;
        cin >> ans;

        if(ans == "YES"){
            names.insert(name);
            if(name.size() > max){
                max = name.size();
                first = name;
            }
        }
    }

    for(itss = names.begin(); itss != names.end(); itss++)
        cout << *itss << "\n";

    cout << "\nAmigo do Habay:\n" << first;

    return 0;
}