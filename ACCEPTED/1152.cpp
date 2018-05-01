#include <stdio.h>

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>

using namespace std;

typedef pair<int, int> ii; // we use ii as a shortcut of integer pair data type
priority_queue< pair<int, ii> > EdgeList; // sort by edge weight O(E log E)
// PQ default: sort descending. To sort ascending, we can use <(negative) weight(i, j), <i, j> >
// for each edge with (i, j, weight) format
//   EdgeList.push(make_pair(-weight, make_pair(i, j)));
// alternative implementation: use STL vector and algorithm:sort

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }



int main(){

	int n, m, i, j = 1, a, b, c, pesoTotal, pesoMinimo;

	while(1){

		scanf("%d %d", &n, &m);
		if(n == m && n == 0)
			break;


		pesoTotal = 0;
		
		for(i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			EdgeList.push(make_pair(-c, make_pair(a, b)));
			pesoTotal += c;
		}
		
		int mst_cost = 0;
		initSet(n); // all V are disjoint sets initially, see Section 2.3.2
		while (!EdgeList.empty()) { // while there exist more edges, O(E)
			pair<int, ii> front = EdgeList.top(); EdgeList.pop();
			if (!isSameSet(front.second.first, front.second.second)) { // if no cycle
				mst_cost += (-front.first); // add (negated) -weight of e to MST
				unionSet(front.second.first, front.second.second); // link these two vertices
			}
		}

		pesoMinimo = mst_cost;

		printf("%d\n", (pesoTotal - pesoMinimo));
	}

	return 0;
}