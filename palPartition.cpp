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
#define INTMAX 1<<30


using namespace std;

bool isPalindrome(string S){
	string::iterator it1 = S.begin();
	string::iterator it2 = S.end()-1;
	while(it1 < it2){
		if(*it1 != *it2) return false;
		it1++;
		it2--;
	}
	return true;
}

int partition(string str, int **part, int start, int end){
	if(start >= end) return 0;
	if(part[start][end] != INTMAX) return part[start][end];

	if(isPalindrome(str.substr(start, end-start+1))) part[start][end] = 0;
	
	else{
		FORF(i,start,end+1){
			part[start][end] = min(part[start][end], 1 + partition(str, part, start, i) + partition(str, part, i+1, end));
		}
	}
	
	return part[start][end];
}

// Given a string, find min. number of cuts to be made, with each substring a palindrome.
int palPartition(string str){
	int len = str.length();
	int **part = new int*[len];
	FORF(i,0,len){ 
		part[i] = new int[len];
		
		FORF(j,0,len) part[i][j] = INTMAX;
		
		part[i][i] = 0;
	}
	
	
	return partition(str, part, 0, len-1);		
}

int main(){
	string str;
	cin >> str;
	cout << palPartition(str) << endl;
	return 0;
}
