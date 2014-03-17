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

typedef struct Edge{
	int src;
	int dest;
	int weight;
}Edge;

typedef struct Graph{
	int V;
	int E;
	struct Edge *edge;	
}Graph;

Graph *createGraph(int V, int E){
	Graph *G = new Graph;
	G->V = V;
	G->E = E;

	G->edge = new Edge[E];

	return G;
}

// given a undirected weighted Graph in adjacency list rep., find the minimum spanning tree for the Graph.
int *kruskalMST(Graph *G){
	
}

Graph *make_graph(){
	int V,E;
	V = 4;
	E = 5;
	Graph *graph = createGraph(V,E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	return graph;
}

int main(){
	Graph *graph = make_graph();
	
	kruskalMST(graph);

	return 0;
}
