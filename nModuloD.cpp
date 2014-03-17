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

#define FORF(i,a,b) for(int i = a; i != b; i++)
#define FORB(i,b,a) for(int i = b; i != a; i--)

// find n modulo d, without using % operator
int nModuloD(int n, int d){
	if(n<d) return n;
	
	int sd = d;
	while((sd<<1) < n){
		sd = sd << 1; 	
	}
	
	return nModuloD(n - sd, d);
}

int main(){
	cout << nModuloD(69,5) << endl;
	return 0;
}
