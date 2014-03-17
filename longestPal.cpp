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

// find the longest palindrome in a string
int longPal(string str){
	int len = str.size();
	
	int OPT = 0;
	int st,nd;

	for(int i = 1; i!= len; i++){
		st = i-1;
		nd = i;

		while(st>=0 && nd < len && str[st]==str[nd]){
			OPT = max(OPT, nd-st+1);
			nd++;
			st--;
		}	
		
		st = i-1;
		nd = i+1;
		
		while(st>=0 && nd < len && str[st]==str[nd]){
			OPT = max(OPT, nd-st+1);
			nd++;
			st--;
		}	
	}

	return OPT;
}

int main(){
	cout << longPal("forgeeksskeegfor") << endl;
	cout << longPal("aaaaa") << endl;
	return 0;
}
