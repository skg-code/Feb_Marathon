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

#define FORF(i,a,b) for(int i = a; i != b; i++)
#define FORB(i,b,a) for(int i = b; i != a; i--)
#define N 3
#define MW 1000

typedef struct Sack{
	int V;
	int W;
}Sack;

//given array of weights and their respective values. Find optimal subset(sum of weights <= WT, max(sum of values)) with no fractions allowed.
// DP : top-down
int knapSack01(Sack *S, int I, int wt, int DP[MW][N]){
	if(I >= N || wt <= 0) return 0;
	if(DP[wt][I] != -1) return DP[wt][I];
	
	int maxKS = 0;
	FORF(i,I,N){
		if(wt >= S[i].W){
			maxKS = max(maxKS, S[i].V + knapSack01(S, i+1, wt - S[i].W, DP));
		}
	}	
	DP[wt][I] = maxKS;
	
	return maxKS;
}

// DP : bottom-up
int knapSack01_(Sack *S, int W){
	int DP[MW][N];

	FORF(i,0,MW) DP[i][0] = ((S[0].W <= i) ? S[0].V : 0);
	FORF(i,0,N) DP[0][i] = 0;

	FORF(i,1,W+1){
		FORF(j,1,N){
			DP[i][j] = max(DP[i][j-1], (i >= S[j].W ? S[j].V + DP[ i - S[j].W ][j-1] : 0));
		}
	}

	return DP[W][N-1];
}

int main(){
	Sack S[] = {{80,70},{50,50},{50,50}};
	int DP[MW][N];
	FORF(i,0,MW) FORF(j,0,N) DP[i][j] = -1;
	cout << knapSack01(S, 0, 100, DP) << endl;	
	cout << knapSack01_(S, 100) << endl;	
	return 0;
}
