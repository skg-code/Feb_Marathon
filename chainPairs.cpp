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

typedef struct Pair{
	int x;
	int y;
}Pair;

int Pairs(Pair *arr, int *DP, int n, int I){
	if(I >= n) return 0;
	if(DP[I] != 0) return DP[I];
	
	DP[I] = 1;
	FORF(j,I+1,n){
		DP[I] = ( (arr[I].y < arr[j].x) ? max( DP[I], 1+Pairs(arr, DP, n, j) ) : DP[I] );
	}	

	return DP[I];
}

// given chain of Pairs, find longest chain such that P[i].second() < P[i+1].first()
int chainPairs(Pair *arr, int n){
	int *DP= new int[n];
	memset(DP, 0, sizeof(DP));

	int res = 1;
	FORF(i,0,n) res = max(res, Pairs(arr, DP, n, i));

	return res;
}

// bottom-up DP
int chainPairsBU(Pair *arr, int n){
	int *DP = new int[n];
	FORF(i,0,n) DP[i] = 1;

	int maxm = 1;
	for(int i = n-1; i!=-1; i--){
		for(int j = i+1; j < n; j++){
			if(arr[i].y < arr[j].x){
				DP[i] = max(DP[i], 1 + DP[j]);
			}
		}
		maxm = max(maxm, DP[i]);
	}


	return maxm;	
}

int main(){
	Pair arr[] = { {5, 24}, {23, 28},
		{27, 40}, {50, 60} };
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << chainPairs(arr, n) << endl;
	cout << chainPairsBU(arr, n) << endl;
	
	return 0;
}
