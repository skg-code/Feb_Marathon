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

// multiply two numbers
int mul2(int Num1, int num2){

	int two = 1; // power of two being multiplied
	int ans = 0;
	while(num2){
		int twoP = 1;
		int num1 = Num1;
		while(twoP + twoP <= num2){
			num1 += num1;
			twoP += twoP;
		}
		two += twoP;
		num2 -= twoP;
		ans += num1;
	}

	return ans;
}


int main(){
	cout << mul2(9,21) << endl;
	return 0;
}
