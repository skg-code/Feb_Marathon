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

#define PF1 2
#define PF2 3
#define PF3 5

// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
int uglyNum(int N){
	int count = 0;
	int ele = 1;

	set<int> S;
	S.insert(ele);

	while(count++ != N){
		ele = *(S.begin());
		
		S.erase(ele);
		
		S.insert(ele*2);
		S.insert(ele*3);
		S.insert(ele*5);
		
		cout << "--" << ele << endl;		
	}
	
	return ele;	
}




int main(){
	cout << uglyNum(15) << endl;
	return 0;
}
