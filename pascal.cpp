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

// print Nth row of pascal triangle
void printPascal(int N){
	cout << 1 << endl;
	
	FOR(i,1,N+1){
		int val = 1;
		FOR(j,0,i+1){
			cout << val << " ";	
			
			int r = j+1;
			val *= (i-r+1);
			val /= r;
		}
		cout << endl;
	}
}

int main(){
	printPascal(9);
	return 0;
}
