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
#define INT_MAX 1<<30 

using namespace std;

int midP(int start, int end){
	return (start+end)/2;
}

void buildSeg(int *seg, int *arr, int start, int end, int I){
	if(start == end){
		seg[I] = arr[start];
		return;
	}

	int mid = midP(start, end);
	buildSeg(seg, arr, start, mid, 2*I+1);
	buildSeg(seg, arr, mid+1, end, 2*I+2);

	seg[I] = min(seg[2*I+1], seg[2*I+2]);
}

int *segRMQ(int *arr, int n){
	int *seg = new int[2*n+1];
	memset(seg, 0, sizeof(seg));
	buildSeg(seg, arr, 0, n-1, 0);
	return seg;
}

int findMin(int *seg, int rs, int re, int start, int end, int I){
	if(rs > end || re < start) return INT_MAX;

	if(rs <= start && re >= end) return seg[I];

	int mid = midP(start, end);

	return min(findMin(seg, rs, re, start, mid, 2*I+1), findMin(seg, rs, re, mid+1, end, 2*I+2));
}

int main(){
	int arr[] = {1, 3, 2, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int *seg = segRMQ(arr, n);
	cout << findMin(seg, 1, 4, 0, n-1, 0) << endl;
	
	return 0;
}
