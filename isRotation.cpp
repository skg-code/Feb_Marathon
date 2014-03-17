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

using namespace std;

#define FORF(i,a,n) for(int i=a;i!=n;i++)
#define FORB(i,n,a) for(int i=n;i!=a;i--)

// check if string A is a rotation of B
bool isRotation(string A, string B){
	string::iterator it1 = A.begin();
	string::reverse_iterator it2 = B.rbegin();

	while(it1 != A.end() && it2 != B.rend()){
		if(*it1 != *it2) return false;
		it1++;
		it2++;
	}
	
	return ( it1 == A.end() && it2 == B.rend() );
}

int main(){
	cout << isRotation("hoki", "kioha") << endl;
	return 0;
}
