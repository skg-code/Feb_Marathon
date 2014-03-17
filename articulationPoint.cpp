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

#define FORF(i,a,n) for(int i=a; i!=n; i++)
#define FORB(i,n,a) for(int i=n; i!=a; i--)

using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // A dynamic array of adjacency lists
	void APUtil(bool *, bool *, int &, int );
	public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // function to add an edge to graph
	void AP();    // prints articulation points
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::APUtil(bool *vis, bool *edg, int &count, int v){
	vis[v] = true;
	if(count==0) cout << v << endl;
	count--;

	list<int>::iterator it;
	
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		int ne = *it;
		if(!edg[ne] && !vis[ne]){
			edg[ne] = true;
			count++;
		}
	}
	
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		int ne = *it;
		if(!vis[ne]){
			APUtil(vis, edg, count, ne);
		}
	}
}

void Graph::AP(){
	bool *vis = new bool[V];
	bool *edg = new bool[V];
	memset(vis, 0, sizeof(vis));
	memset(edg, 0, sizeof(vis));
	int count = 0;
	APUtil(vis, edg, count, 0);
}

// Driver program to test above function
int main()
{
	// Create graphs given in above diagrams
	cout << "\nArticulation points in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.AP();

	cout << "\nArticulation points in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.AP();

	cout << "\nArticulation points in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.AP();

	return 0;
}
