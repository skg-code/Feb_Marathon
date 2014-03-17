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

#define AL 26

// repetition allowed
void permString(int l, string S, int L, string &inp){
	if(L == l){
		cout << S << endl;
		return;
	}

	FORF(i,0,L){
		
			permString(l+1, S+inp[i], L, inp);
	
	}

}

void swap(char *a, char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// all the permutations of a given string
void permString_(char *S, int i, int n){
	if(i == n){
		cout << S << endl;
		return;
	}

	FORF(j,i,n){
		swap(S+i, S+j);
		
		permString_(S, i+1, n);

		swap(S+i, S+j);
	}
}

int main(){
	string inp = "abc";
	string S = "";
	permString(0, S, inp.size(), inp);
/*	
	char str[] = "ABC";	
	permString_(str, 0, strlen(str));
*/
	return 0;
}
