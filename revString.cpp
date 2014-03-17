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

// reverse a string using recursion
void printRevString(string &S, string::iterator it){
	if(it == S.end()) return;

	printRevString(S, it+1);

	cout << *it;
}

int main(){
	string S = "justBringIt";
	printRevString(S, S.begin());
	cout << endl;
	return 0;
}
