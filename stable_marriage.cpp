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

#define N 4
#define FOR(i,a,b) for(int i=a;i!=b;i++)
// Find mapping, so that preferences are optimally allotted and marriages are stable.
void engage(int prefer[2*N][N]){
	vector<bool> MW(N,false);
	vector<int> mP(N,0);
	vector<int> wP(N,-1);

	deque<int> Q;
	
	FOR(i,0,N) Q.push_back(i);
	
	int M;
	int W;
	
	while(Q.size()){
		
		M = Q.front();
		Q.pop_front();
		
		for(mP[M]; mP[M]!=N; mP[M]++){
			bool fl = false;
			W = prefer[M][ mP[M] ];
			if(!MW[ W - N ]){
				wP[ W - N ] = M;
				MW[ W - N ] = true;
				break;
			}
			else{
				FOR(i,0,N){
					if(prefer[W][i] == M){
						Q.push_back(wP[ W - N ]);
						wP[ W - N ] = M;
						fl = true;
						break;
					}
					else if(prefer[W][i] == wP[ W - N ]){
						break;
					}
				}
			}
			
			if(fl) break;
		}
	
	}

	FOR(i,0,N){
		cout << wP[ i ] << " " << i+N << endl;
	}

}

int main(){
	
	int prefer[2*N][N] = { 
		{7, 5, 6, 4},
		{5, 4, 6, 7},
		{4, 5, 6, 7},
		{4, 5, 6, 7},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 1, 2, 3},
	};	

	engage(prefer);

	return 0;
}
