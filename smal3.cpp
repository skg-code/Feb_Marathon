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

// find min of 3 numbers, without using comparison operators.
int smal3(int a,int b){
	return ((a-b)>>31 & a) | ((b-a)>>31 & b);
}

int main(){
	cout << smal3(smal3(-15,-12),12) << endl;	
	return 0;
}
