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

int maxSumInc(int *arr, int n){
	int *MAX = new int[n];
	FORF(i,0,n) MAX[i] = arr[i];

	int OPT = 0;
	FORB(i,n-1,-1){
		FORF(j,i+1,n){
			if(arr[j] > arr[i]) MAX[i] = max(MAX[i], arr[i] + MAX[j]);
		}
		
		OPT = max(OPT, MAX[i]);
	}
	
	return OPT;
}

int main(){
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << maxSumInc(arr, n) << endl;
	return 0;
}
