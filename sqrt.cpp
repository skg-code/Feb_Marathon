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
#define e 0.0000000001
#define LL double

using namespace std;

// babylonian method
LL squareRoot(int N){
	LL x = N;
	LL y = 1;
	
	while(x - y > e){
		cout << x << " " << y << endl;
		x = (x+y)/2;
		y = N/x;
	}

	return x;
}

int main(){
	cout << squareRoot(10) << endl;
	return 0;
}
