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

// find number of set bits between 0,n
int numBits(int n,int *arr){
	if(n == 0) return 0;
	if(n == 1) return 1;

	int m = log2(n);
	
	if(!arr[m])	
		for(int i=0;i!=m;i++){
			if(!arr[i+1])
				arr[i+1] = 2*arr[i] + (1<<i);
		}
	
	return 1 + arr[m] + (n - (1<<m)) + numBits(n - (1<<m), arr);
}

int main(){
	int N;
	cin >> N;
	int arr[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cout << numBits(N,arr) << endl;
	return 0;
}
