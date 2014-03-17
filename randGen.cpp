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
void randGenK(int, int, int *);
void randGen(int, int, int *);

// pick k random numbers from a stream, with distributed probability.
void randGenK(int n, int k, int *arr){
	int stream;
	FOR(i,0,k){
		cin >> stream;
		arr[i] = stream;
	}

	FOR(i,k,n){
		cin >> stream;
		int randS = rand()%(i+1);
		if(randS < k) arr[randS] = stream;
	}

	return;
}


// pick a random number from a stream, with distributed probability.
void randGen(int n){
	int stream;
	int randS;
	
	cin >> stream;
	randS = stream;
	cout << "---" << randS << endl;
	
	FOR(i,1,n){
		cin >> stream;
		
		int ranD = rand()%(i+1);
		
		if(ranD == i){
			randS = stream;
		}
		
		cout << "---" << randS << endl;
	}
	return;
}


int main(){
	int n,k;
	cin >> n >> k;
	int *arr = new int[k];
	randGen(n);
	return 0;
}
