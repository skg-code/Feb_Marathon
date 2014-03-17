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

// print binary representation of a number
void printBin(int N,int i){
	if(i == 32) return;

	printBin(N,i+1);

	cout << (bool)((N)&(1<<i));
}

int main(){
	int N;
	cin >> N;
	
	printBin(N,0);
	cout << endl;
	
	return 0;
}
