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

#define FORF(i,a,n) for(int i=a; i!=n; i++)
#define FORB(i,n,a) for(int i=n; i!=a; i--)
#define V 9
#define INTMAX 1<<30

typedef struct Node{
	int D;
	int N;
}Node;

class compare{
	public:
		bool operator()(const Node& A, const Node& B){
			return A.D > B.D;
		}	
};

int *dijkstra(const int graph[V][V], int source){
	int src = source;
	int *dist = new int[V];
	FORF(i,0,V) dist[i] = INTMAX;
	dist[src] = 0;
	
	bool vis[V] = {false};
	
	vector<Node> VN;
	Node node = {0, src};
	
	VN.push_back(node);
	make_heap(VN.begin(), VN.end(), compare());
	
	int count = 0;
	while(count != V){
		src = VN.front().N;
		pop_heap(VN.begin(), VN.end(), compare()); VN.pop_back();

		if(!vis[src]){
			FORF(i,0,V){

				if(graph[src][i] != 0 && !vis[i]){
					dist[i] = min(dist[i], dist[src] + graph[src][i]);
					node = {dist[i], i};

					VN.push_back(node); push_heap(VN.begin(), VN.end(), compare());
				}


			}
			vis[src] = true;
			count++;
		}
	}
	
	cout << "Source: " << source << endl;
	FORF(i,0,V){
		cout << "Destination: " << i << " ";
		cout << dist[i] << endl;
	}
	
	return dist;
}

int main(){
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 0, 10, 0, 2, 0, 0},
		{0, 0, 0, 14, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0}
	};			      
	
	int *dist = dijkstra(graph, 8);
	
	return 0;
}
