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

#define FOR(i,a,n) for(int i=a;i!=n;i++)

using namespace std;

//Given 'sum', check if a subset of set equals sum.
bool isSubsetSum(int sum, int *set, int N){
	bool sSum[sum+1][N+1];
	
	for(int i=0;i!=sum+1;i++)
		sSum[i][0] = false;
	
	for(int i=0;i!=N+1;i++)
		sSum[0][i] = true;
	
	for(int i = 1;i!=sum+1;i++){
		for(int j=1;j!=N+1;j++){
			sSum[i][j] = sSum[i][j-1];
			if(i>=set[j-1])
				sSum[i][j] = sSum[i][j] | sSum[i - set[j-1] ][j-1];
		}
	}
	return sSum[sum][N];
}


int main(){
	int set[] = {3,34,4,12,5,2};
	int N = sizeof(set)/sizeof(set[0]);

	cout << (isSubsetSum(92,set,N)?"True":"false") << endl;
	
	return 0;
}
