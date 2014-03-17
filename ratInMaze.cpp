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

int UL;

int pX[] = {0,1,-1,0,-1,1,1,-1};
int pY[] = {1,1,1,-1,-1,-1,0,0};

bool isValid(bool **, bool **, int, int);
void printSol(bool **);
bool ratInMazeBT(bool **, bool **, int, int);

bool isValid(bool **path, bool **occ, int x, int y){
	return (x >= 0 && x < UL && y >=0 && y < UL && !occ[x][y] && path[x][y]);
}

void printSol(bool **occ){
	FORF(i,0,UL){
		FORF(j,0,UL){
			cout << occ[i][j] << " ";
		}
		cout << endl;
	}
}

// find path in a maze from 0,0 to UL-1, UL-1(level : complex)
// path - given , occ - path occupied till then
bool ratInMazeBT(bool **path, bool **occ, int x, int y){
	if(x == UL-1 && y == UL-1){
		printSol(occ);
		return true;
	}

	FORF(i,0,8){
		int X = x + pX[i];
		int Y = y + pY[i];
		if(isValid(path, occ, X, Y)){
			occ[X][Y] = true;
			if(ratInMazeBT(path, occ, X, Y)){
				return true;
			}
			occ[X][Y] = false;
		}
	}
	return false;
}

int main(){
	UL = 4;
	bool Temp[][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
	bool **path = new bool *[UL];
	bool **occ = new bool *[UL];
	FORF(i,0,UL){
		path[i] = new bool[UL];
		occ[i] = new bool[UL];
		FORF(j,0,UL){
			path[i][j] = Temp[i][j];
			occ[i][j] = 0;
		}
	}
	occ[0][0] = true;
	cout << (ratInMazeBT(path, occ, 0, 0) ? "Possible":"Not Possible") << endl;
	return 0;
}
