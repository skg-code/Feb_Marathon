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

// Given a number x and two positions (from right side) in binary representation of x, write a function that swaps n bits at given two positions and returns the result.
int swapN(int N,int p1,int p2,int n){
	int bMask = (1<<n) - 1;
	
	int bMask1 = (bMask<<p1);
	bMask1 &= N;
	N ^= bMask1;	
	bMask1 = bMask1 << p2-p1;

	int bMask2 = (bMask<<p2);
	bMask2 &= N;
	N ^= bMask2;	
	bMask2 = bMask2 >> p2-p1;
	
	return N|bMask1|bMask2;	
}

int main(){
	cout << swapN(28,0,3,2) << endl;
	return 0;
}
