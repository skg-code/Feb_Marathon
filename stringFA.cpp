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
#define CH 256

// function to find longest proper prefix, which is a proper suffix of str
int longPS(string str, char ch){
	str += ch;
	int len = str.length();
	
	FORB(i, len-1, 0){
		if(str.substr(0,i) == str.substr(len - i, i)) return i;
	}

	return 0;	
}

// filling FA table
void fillFA(int FA[][CH], string A, int len1){
	FORF(i,0,len1){
		FA[i][ A[i] ] = i+1;
		
		FORF(j,0,CH){
			if(j != A[i]) FA[i][j] = longPS(A.substr(i,i+1), j);
		}
	}	
}

// check match with FA table
bool checkMatch(int FA[][CH], string str, int final){
	int len = str.length();

	int st = 0;
	FORF(i,0,len){
		st = FA[st][ str[i] ];
		if(st == final) return true;
	}

	return false;
}

// check string match using finite automata
bool stringFA(string A, string B){
	int len = A.length();
	
	int FA[len][CH];
       	memset(FA, 0, sizeof(FA));	

	fillFA(FA, A, len);

	return checkMatch(FA, B, len);
}

int main(){
	cout << stringFA("DAAB","AABAACAADAABAAABAA") << endl;		
	return 0;
}
