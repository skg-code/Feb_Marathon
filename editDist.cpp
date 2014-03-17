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

using namespace std;

#define FORF(i,a,n) for(int i=a;i!=n;i++)
#define FORB(i,n,a) for(int i=n;i!=a;i--)
#define SIZE 20


int editDist(char *, char *, int **);

// Given 2 strings, find the minimum number of operations(add, del, replace) needed to change one to another
int editDist(char *str1, char *str2, int **mem){
	int m = strlen(str1);
	int n = strlen(str2);
	if(mem[m][n]!=-1) return mem[m][n];
	
	if(*str1 == '\0') return n;
	if(*str2 == '\0') return m;

	if(*str1 == *str2) {
		mem[m][n] = editDist(str1+1, str2+1, mem);
	}
	
	else {
		mem[m][n] = 1 + min(min(editDist(str1+1, str2, mem),editDist(str1, str2+1, mem)), editDist(str1+1, str2+1, mem));
	}

	return mem[m][n];
}


int main(){
	char str1[] = "monday";
	char str2[] = "saturday";
	
	int **mem = new int*[SIZE];
	FORF(i,0,SIZE){
		mem[i] = new int[SIZE];
		FORF(j,0,SIZE)
			mem[i][j] = -1;
	}

	cout << editDist(str1, str2, mem) << endl;
	return 0;
}
