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

void probDist(int *, int *, int);
int bins(int, int *, int, int);

// Given numbers and their frequencies. Make a probability distribution on them to return a random number.
void probDist(int *arr, int *freq, int N){
	int base = 0;
	int *wind = new int[N];
	FOR(i,0,N){ 
		
		// windows from 0 to base - 1;
		wind[i] = base;
		
		base += freq[i];
	}

	FOR(i,0,10){
		int RAN = rand()%base;
		cout << bins(RAN, wind, 0, N-1) << endl;
	}

		
}

int bins(int RAN, int *wind, int start, int end){
	if(start == end) return start;	
	
	int mid = (start + end)/2;
	
	if(RAN >= wind[mid] && mid+1 <= end){ 
		if(RAN < wind[mid+1]) return mid;

		return bins(RAN, wind, mid+1, end);
	}
	
	if(RAN < wind[mid] && mid-1 >= start) {
		if(RAN >= wind[mid-1]) return mid-1;
	
		return bins(RAN, wind, start, mid-1);
	}

}


int main(){
	int arr[] = {10, 30, 20, 40};
	int freq[] = {1, 2, 9, 6};
	int N = sizeof(arr)/sizeof(arr[0]);
	probDist(arr, freq, N);
	return 0;
}
