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
#define INTMAX 1<<30

using namespace std;

// Given an array of integers, each representing num of jumps allowed from that. Find min to reach end of the array.
int minJumps(int *arr, int n){
	int *MIN = new int[n];
	
	FORF(i,0,n) MIN[i] = INTMAX;
	MIN[n-1] = 0;
	
	FORB(i,n-2,-1){
		for(int j = 1; j != arr[i]+1 && i+j < n; j++){
			MIN[i] = min(MIN[i], 1+MIN[i+j]);
		}
	}

	return MIN[0];
}

int main(){
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << minJumps(arr, n) << endl;
	return 0;
}
