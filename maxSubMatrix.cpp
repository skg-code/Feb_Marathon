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
#define R 6
#define C 5

int maxSubMatrix(bool );

// find maximum submatrix with all '1'
int maxSubMatrix(bool M[R][C]){
	vector< vector<int> > SV(R, vector<int> (C,0));
	for(int i=0; i!=R; i++) SV[i][0] = M[i][0];
	for(int i=0; i!=C; i++) SV[0][i] = M[0][i];
	
	int maxS = 0;
	for(int i=1; i!=R; i++){
		for(int j=1; j!=C; j++){
			int sLU = 1;
			for(int k=1; k!=SV[i-1][j-1]+1; k++) if(!M[i][j-k] || !M[i-k][j]){sLU = 0; break;}
			SV[i][j] = M[i][j]*sLU*(SV[i-1][j-1] + 1);
			maxS = max(maxS, SV[i][j]);	
		}
	}

	return maxS;
}


int main(){
	bool M[R][C] =  {{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}};
	
	cout << maxSubMatrix(M) << endl;
	
	return 0;
}
