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
#define AL 256

using namespace std;

// Given a string, find a substring with no repeating chars
int longNoRep(string S){
	int len = S.length();
	int pos[AL] = {-1};

	int MAX = 0;
	int DP = 0;
	FORF(i,0,len){
		if(pos[ S[i] ] < i - DP) DP += 1;
		else DP = i - pos[ S[i] ];

		pos[ S[i] ] = i;
		MAX = max(MAX, DP);
	}

	return MAX;
}

int main(){
	cout << longNoRep("000000") << endl;
	return 0;
}
