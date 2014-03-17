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

using namespace std;

typedef struct Pair{
	int key;
	int frq;
}Pair;

int compare(const void *A, const void *B){
	return ( ((Pair *)B)->frq - ((Pair *)A)->frq );
}

int optBinTree(Pair *P, int n){
}

int main(){
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	
	Pair *P = new Pair[n];
	FORF(i,0,n){
		P[i].key = keys[i];
		P[i].frq = freq[i];
	}
	
	qsort(P, n, sizeof(P[0]), compare);	
	
	cout << optBinTree(P, n) << endl;			

	return 0;
}
