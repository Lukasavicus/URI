/* Lukasavicus - 1861 */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

typedef vector<string> vs;
typedef map<string,int> msi;

int main(){
    
    string murder, murdered;
    msi hall_of_murderers;
    vs murdereds;
    map<string,int>::iterator it;
    
    while(1){
    	cin >> murder >> murdered;
    	if(cin.eof())
			break;
        ++hall_of_murderers[murder];
        murdereds.push_back(murdered);
    }
    
    for(int i = 0; i < murdereds.size(); i++)
    	hall_of_murderers.erase(murdereds[i]);

    cout << "HALL OF MURDERERS\n";
    
    for (it=hall_of_murderers.begin(); it!=hall_of_murderers.end(); ++it)
        cout << it->first << ' ' << it->second << "\n";

	return 0;
}