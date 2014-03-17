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
#define LL 0
#define UL 16

bool isValid(int **, int, int);
void printSol(int **);
bool nQueens(int **, int);

bool isValid(int **V, int x, int y){
	for(int i = LL; i!=x; i++){
		if(V[i][0] == x || V[i][1] == y || (abs(V[i][1]-y) == abs(V[i][0]-x))) return false;
	}
	return true;
}

void printSol(int **V){
	FORF(i,0,UL)
		cout << V[i][0] << " " << V[i][1]<<endl;
}

// Find vertices in a square board, which have no diagonal or vertical or horizontal alignment
bool nQueens(int **V, int L){
	if(L == UL){
		printSol(V);
		return true;
	}

	FORF(i, LL, UL){
		if(isValid(V, L, i)){
			
			V[L][0] = L;
			V[L][1] = i;
			if(nQueens(V, L+1)){
				return true;
			}
			
			V[L][0] = -1;
			V[L][1] = -1;
		}
	}
	
	return false;
}

int main(){
	int **V = new int*[UL];
	FORF(i,0,UL){
		V[i] = new int[2];
		
		V[i][0] = -1;
		V[i][1] = -1;
	}
	
	cout << (nQueens(V, 0) ? "Possible":"Impossible") << endl;

	return 0;
}
