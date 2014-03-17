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

bool isBound(int r, int c, int n){
	return ( r>=0 && r<n && c>=0 && c<n );
}

// A matrix is row-wise and column-wise sorted, find a queried element in it.
bool matSearch(int mat[4][4], int n, int ele){
	int r = 0, c = n-1;

	while(1){
		if(isBound(r,c,n)){
			if(mat[r][c] > ele){
				c--;
			}
			else if(mat[r][c] < ele){
				r++;
			}
			else return true;
		}
		else return false;
	}

	return false;
}

int main(){
	int mat[4][4] = { {10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50},
	};
	
	cout << matSearch(mat, 4, 31) << endl;

	return 0;
}
