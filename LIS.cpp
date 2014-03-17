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

#define FOR(i,a,n) for(int i=a;i!=n;i++)

int longInc(int *, int N, int *);

// longest increasing subsequence of an array
int longInc(int *arr, int N, int *longArr){
	for(int i = N-1; i!=-1; i--){
		FOR(j,i+1,N){
			if(arr[j] > arr[i] && longArr[j]+1 > longArr[i]){
				longArr[i] = longArr[j]+1;
			}
		}
	}
	int maxL = 0;
	FOR(i,0,N){
		maxL = max(maxL, longArr[i]);
	}
	return maxL;
}


int main(){
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
	int N = sizeof(arr)/sizeof(arr[0]);
	int *longArr = new int[N];
	FOR(i,0,N) longArr[i] = 1;
	cout << longInc(arr, N, longArr) << endl;
	return 0;
}
