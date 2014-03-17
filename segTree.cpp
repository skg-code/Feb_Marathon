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

int midP(int, int);
void buildTree(int *, int *, int, int, int);
int *segTree(int *, int);
int rangeSum(int *, int, int, int ,int, int);

int midP(int start, int end){
	return (start + end)/2;
}

void buildTree(int *seg, int *arr, int start, int end, int I){
	if(start == end){
		seg[I] = arr[start];
		return;
	}
	
	int mid = midP(start, end);
	buildTree(seg, arr, start, mid, 2*I+1);
	buildTree(seg, arr, mid+1, end, 2*I+2);
	seg[I] = seg[2*I+1] + seg[2*I+2];
}

int *segTree(int *arr, int n){
	int *seg = new int[2*n + 1];
	memset(seg, 0, sizeof(seg));
	
	buildTree(seg, arr, 0, n-1, 0);	
	return seg;
}

int rangeSum(int *seg, int rs, int re, int start, int end, int I){
	if(rs <= start && re >= end) return seg[I];
	if(re < start || rs > end) return 0;

	int mid = midP(start, end);
	return rangeSum(seg, rs, re, start, mid, 2*I+1) + rangeSum(seg, rs, re, mid+1, end, 2*I+2);	
}

void updateSeg(int in, int dif, int *seg, int start, int end, int I){
	if(start >= end) return;
	
	if(in >= start && in <= end){
		seg[I] += dif;
		int mid = midP(start, end);
		updateSeg(in, dif, seg, start, mid, 2*I+1);
		updateSeg(in, dif, seg, mid+1, end, 2*I+2);
	}
}

void updateArr(int I, int val, int *arr, int *seg, int start, int end){
	int dif = val - arr[I];
	arr[I] = val;
	updateSeg(I, dif, seg, start, end, 0);
}

int main(){
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]); 
	int *seg = segTree(arr, n);
	
	cout << rangeSum(seg, 0, 4, 0, n-1, 0) << endl;
	
	updateArr(2, 14, arr, seg, 0, n-1);
	
	cout << rangeSum(seg, 0, 4, 0, n-1, 0) << endl;
	
	return 0;
}
