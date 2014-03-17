#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

#define FORF(i,a,n) for(int i=a;i!=n;i++)
#define FORB(i,n,a) for(int i=n;i!=a;i--)
#define V 5

bool hamCycleF(bool graph[V][V], bool *vis, int node, int count, int head){
	if(count == V) return graph[node][head];
	
	FORF(i,0,V){
		if(graph[node][i] && !vis[i]){
			vis[i] = true;
			if(hamCycleF(graph, vis, i, count+1, head)) return true;
			vis[i] = false;
		}
	}

	return false;
}

// Given a graph, find if there's a hamiltonian cycle in the graph
// Hamiltonian path is a path in an undirected or directed graph that visits each vertex exactly once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian path that is a cycle.
bool hamCycle(bool graph[V][V]){
	bool vis[V] = {false};
	
	FORF(i,0,V){
		vis[i] = true;
		if(hamCycleF(graph, vis, i, 1, i)) return true;
		vis[i] = false;
	}

	return false;
}

int main(){
	
	bool graph1[][V] = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1, 0}};
	cout << (hamCycle(graph1) ? "Yes":"No") << endl;
	
	bool graph2[][V] = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 0},{0, 1, 1, 0, 0}};
	cout << (hamCycle(graph2) ? "Yes":"No") << endl;
	
	return 0;
}
