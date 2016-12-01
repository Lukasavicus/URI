/* Lukasavicus - 1261 */

#include <iostream>
#include <string>
#include <map>

#define MAX 101

using namespace std;

typedef map<string, int> msi;
typedef pair<string, int> psi;

int main(){

	msi hay;
	string leitor;
	
	int n_palavras, i, valor, n_cargos;
	
	cin >> n_palavras;
	cin >> n_cargos;
	
	while(n_palavras--){
		cin >> leitor;
		cin >> valor;
		hay.insert(psi(leitor, valor));
	}
	
	i = 0;
	valor = 0;
	while(i < n_cargos){
		cin >> leitor;
		
		if(hay.find(leitor) != hay.end())
			valor += hay[leitor];
			
		if(leitor == "."){
			cout << valor << "\n";
			valor = 0;
			i++;
		}
	}

	return 0;
}