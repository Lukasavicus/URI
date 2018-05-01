/* Lukasavicus - 1763 */

#include <stdio.h>

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main(){
    
    map<string, string> table;

    table["brasil"] =               "Feliz Natal!";
    table["alemanha"] =             "Frohliche Weihnachten!";
    table["austria"] =              "Frohe Weihnacht!";
    table["coreia"] =               "Chuk Sung Tan!";
    table["espanha"] =              "Feliz Navidad!";
    table["grecia"] =               "Kala Christougena!";
    table["estados-unidos"] =       "Merry Christmas!";
    table["inglaterra"] =           "Merry Christmas!";
    table["australia"] =            "Merry Christmas!";
    table["portugal"] =             "Feliz Natal!";
    table["suecia"] =               "God Jul!";
    table["turquia"] =              "Mutlu Noeller";
    table["argentina"] =            "Feliz Navidad!";
    table["chile"] =                "Feliz Navidad!";
    table["mexico"] =               "Feliz Navidad!";
    table["antardida"] =            "Merry Christmas!";
    table["canada"] =               "Merry Christmas!";
    table["irlanda"] =              "Nollaig Shona Dhuit!";
    table["belgica"] =              "Zalig Kerstfeest!";
    table["italia"] =               "Buon Natale!";
    table["libia"] =                "Buon Natale!";
    table["siria"] =                "Milad Mubarak!";
    table["marrocos"] =             "Milad Mubarak!";
    table["japao"] =                "Merii Kurisumasu!";

    string s;

    while(1){
        cin >> s;
        if(cin.fail())
            break;
        if(table.find(s) == table.end())
            printf("--- NOT FOUND ---\n");
        else
            cout << table[s] << "\n";
    }

    return 0;
}