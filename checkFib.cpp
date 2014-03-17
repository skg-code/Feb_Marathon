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
#define INPUT 55
#define GUESS 27

// check if a number is from the fibonacci sequence
// guess the previous number and check 
int checkFib(int inp1, int inp2, int count = 1){
	if(inp2 <= 2) return count;

	return checkFib(inp2,inp1 - inp2, count+1);
}


int main(){
	for(int i = 1; i <= 155; i = i<<1){
		cout << GUESS + i << " ";
		cout << checkFib(INPUT,GUESS+i) << endl;
	}
	return 0;
}
