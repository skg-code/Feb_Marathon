#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime> 

using namespace std;

// find min. in a rotated sorted array
int print_min(vector<int> V,int st,int nd){
	int mid = (st + nd)/2;
	if(st == nd) return V[st];
	if(V[mid] <= V[mid-1]) return V[mid];
	if(V[mid] <= V[st]) return print_min(V,st,mid-1);
	if(V[nd] <= V[mid]) return print_min(V,mid+1,nd);

	return V[st];
}

int main(){
	vector<int> V;
	int N;
	while(scanf("%d",&N)){
		V.push_back(N);
	}
	cout << print_min(V, 0, V.size()-1) << endl;
	return 0;
}
