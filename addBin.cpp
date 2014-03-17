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

// Add two numbers without explicit use of +,-,*,/
int addBin(int a,int b){
	int A = a^b;
	int B = a&b;
	B = B<<1;

	a = A^B;
	b = A&B;
	b = b << 1;

	return a|b;
}


int main(){
	cout << addBin(-13,-28) << endl;	
	return 0;
}
