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
#define UL 8
#define LL 0
#define END 64

bool SET;

void knighTourBT(int **, int, int, int);
bool checkBound(int, int, int **);
void printPath(int **);

bool checkBound(int x, int y, int **B){
	return (x >= LL && x < UL && y >= LL && y < UL && B[x][y] == -1);
}

void printPath(int **B){
	FORF(i,0,UL){
		FORF(j,0,UL){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	
	return;
}

// Find a path for the knight to tour the chess board, visiting all the squares, exactly once.
void knighTourBT(int **B, int x, int y, int count){
	if(count == END){
		SET = true;
		printPath(B);
		return;
	}

	int X,Y; 
	
	X = x+2;
	Y = y+1;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x+1;
	Y = y+2;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x-1;
	Y = y+2;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x-2;
	Y = y+1;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x-2;
	Y = y-1;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x-1;
	Y = y-2;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x+1;
	Y = y-2;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	X = x+2;
	Y = y-1;
	if(checkBound(X, Y, B)){
		B[X][Y] = count;
		knighTourBT(B, X, Y, count+1);
		if(SET) return;
		B[X][Y] = -1;
	}

	return;
}

int main(){
	int **B = new int*[UL];
	FORF(i,0,UL){
		B[i] = new int[UL];
		FORF(j,0,UL)
			B[i][j] = -1;
	}
	
	SET = false;	
	B[0][0] = 0;
	knighTourBT(B, 0, 0, 1);
	
	return 0;
}
