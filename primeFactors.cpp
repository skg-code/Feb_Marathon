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

// find all the prime factors of N
void primeFactors(int N){
	while(N%2 == 0){
		cout << "2 ";
		N /= 2;
	}

	for(int i = 3; i <= sqrt(N); i+=2){
		while(N%i == 0){
			cout << i << " ";
			N /= i;
		}
	}
	if(N > 2) cout << N;

	cout << endl;

}

int main(){
	primeFactors(315);
	return 0;
}
