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

// given two vessel capacities, find if operations Fill, clear, transfer between them can result in '1' in either of them 
int vessels(int A,int B){
	int D = B/A + 1;
	return (A-1)*D;	
}

int main(){
	cout << vessels(3,7) << endl;
	return 0;
}
