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

int LCS(char *, int, char *, int, int **, int, int);

// Find the longest common subsequence for two given strings
int LCS(char *str1, int start1, char *str2, int start2, int ** lc, int M, int N){
	if(start1 >= M || start2 >= N) return 0;
	if(lc[start1][start2] != -1) return lc[start1][start2];


	if(str1[start1] == str2[start2]){
		lc[start1][start2] = 1 + LCS(str1, start1+1, str2, start2+1, lc, M, N);
	}

	else lc[start1][start2] = max(LCS(str1, start1+1, str2, start2+1, lc, M, N), max(LCS(str1, start1+1, str2, start2, lc, M, N), LCS(str1, start1, str2, start2+1, lc, M, N)));
	
	return lc[start1][start2];
}

int main(){
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);
	
	int **lc = new int*[m];
	FORF(i,0,m){ 
		lc[i] = new int[n];
		FORF(j,0,n) lc[i][j] = -1;
	}

	printf("Length of LCS is %d\n", LCS(X,0,Y,0,lc,m,n) );
	return 0;
}
