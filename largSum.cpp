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

int largSum(int *, int, int);

// given an array, find the largest sum possible for a subset of elements.
int largSum(int *arr, int start, int end){
	if(start >= end){
		if(arr[start]>0) return arr[start];

		return 0;
	}
	
	
	int mid = (start + end)/2;

	int med = 0;
	int medL = 0,maxL = 0;
	int medR = 0,maxR = 0;
	for(int i = mid - 1; i>=0; i--){
		medL += arr[i];
		maxL = max(maxL, medL);
	}

	for(int i = mid + 1; i<=end; i++){
		medR += arr[i];
		maxR = max(maxR, medR);
	}
	
	med = arr[mid] + maxL + maxR;
	
	return max(max(largSum(arr, start, mid - 1),largSum(arr, mid + 1, end)), med);
}

int main(){
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout << largSum(arr, 0, N-1) << endl;
	return 0;
}
