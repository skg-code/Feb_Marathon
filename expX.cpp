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
#define PREC 0.0001


using namespace std;


// calculae e^x
double expX(double x, double L = 1){
	if(x/L <= PREC) return 1;
	
	return 1 + (x/L)*expX(x, L+1);
}


int main(){
	cout << expX(1) << endl;
	return 0;
}
