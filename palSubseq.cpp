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

int palSubseq(char *seq, int start, int end, int **DP){
	if(start > end) return 0;
	if(start == end) return 1;
	if(DP[start][end] != 0) return DP[start][end];	

	DP[start][end] = max(max(palSubseq(seq, start+1, end, DP), palSubseq(seq, start, end-1, DP)), 2*(seq[start] == seq[end]) + palSubseq(seq, start+1, end-1, DP));

	return DP[start][end];
}

int main(){
	char seq[] = "BBABCBCAB";
	int n = strlen(seq);
	
	int **DP = new int*[n];
	FORF(i,0,n) DP[i] = new int[n];
	
	cout << palSubseq(seq, 0, n-1, DP) << endl;
	
	return 0;
}
