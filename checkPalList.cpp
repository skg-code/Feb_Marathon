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

typedef struct List{
	int num;
	List *next;
}List;

// check if the given list is a palindrome
List *pal(List *L,int N,int l){
	if(l == N/2+1){
		if(N%2) return L->next;
		return L;
	}
	List *T = pal(L->next,N,l+1);
	if(L->num == T->num) return T->next;

	return T;
}


int main(){
	List *ML = new List;
	List *LL = ML;
	int N;
	cin >> N;
	FOR(i,0,N){
		cin >> ML->num;
		if(i == N-1)ML->next = NULL;
		else ML->next = new List;
		ML = ML->next;
	}
	if(N <= 1) cout << "YES" << endl;
	else{
		if(pal(LL,N,1)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
