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
#define MAXD 1<<30

using namespace std;

typedef struct Edge{
	int src;
	int dest;
	int weight;
}Edge;

typedef struct Graph{
	int V;
	int E;
	Edge *edge;	
}Graph;

Graph *createGraph(int V, int E){
	Graph *G = new Graph;
	G->V = V;
	G->E = E;
	G->edge = new Edge[E];
	
	return G;	
}

// DP solution
void DP(int src, int *dist, Graph *G){
	
	FORF(i,1,G->V){
		FORF(j,0,G->E){
			int S = G->edge[j].src;
			int D = G->edge[j].dest;
			int W = G->edge[j].weight;

			dist[D] = min(dist[D], dist[S] + W);
		}

		FORF(i,0,G->V){
			cout << src << " " << i << " path - " << dist[i] << endl;
		}
		cout << "-------------------" << endl;
	}	

	return;
}

// shortest path to all vertices from a single source, using DP
void BellmanFord(Graph *G, int src){
	int *dist = new int[G->V];	
	
	FORF(i,0,G->V){
		dist[i] = MAXD;
	}
	
	dist[src] = 0;
	DP(src,dist,G);
	

	return;
}

int main(){
	int V = 5;  // Number of vertices in graph
	int E = 8;  // Number of edges in graph
	Graph *graph = createGraph(V, E);

	// add edge 0-1 (or A-B in above figure)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	// add edge 0-2 (or A-C in above figure)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 1-4 (or A-E in above figure)
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	BellmanFord(graph, 0);    
	return 0;
}
