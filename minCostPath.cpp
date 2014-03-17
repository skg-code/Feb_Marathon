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
#define INT_MAX 1000

void minCostPath(int **, int, int);

// min cost from 0,0 to m,n
int minCostPath(int cost[3][3], int path[3][3], int m, int n){
	if(m<0 || n<0) return INT_MAX;
	if(m==0 && n==0) return cost[0][0];
	if(path[m][n]!=-1) return path[m][n];
	
	path[m][n] = cost[m][n] + min(minCostPath(cost, path, m-1, n-1), min(minCostPath(cost, path, m-1, n), minCostPath(cost, path, m, n-1))); 
	
	return path[m][n];
}

int main(){
	int cost[3][3] = { {1, 2, 3},
		{4, 8, 2},
		{1, 5, 3} };
	
	int path[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};

	cout << minCostPath(cost, path, 2, 2) << endl;	
	return 0;
}
