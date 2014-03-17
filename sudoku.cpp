#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FORF(i,a,n) for(int i=a;i!=n;i++)
#define FORB(i,n,a) for(int i=n;i!=a;i--)
#define N 9

typedef struct point{
	int x;
	int y;
}point;

bool isValid(int, int, int, int);
bool sudokuBT(int, point *, int, int);
bool sudoku(int );

bool isValid(int K, int grid[N][N], int R, int C){
	FORF(i,0,N) if(grid[i][C] == K || grid[R][i] == K) return false;
	
	int N_ = (int)sqrt(N);
	C /= N_;
	R /= N_;
	
	FORF(i,0,N_){
		FORF(j,0,N_){
			if(grid[i+N_*R][j+N_*C] == K) return false;
		}
	}

	return true;
}

bool sudokuBT(int grid[N][N], point *P, int num, int count = 0){
	if(count == num) return true;

	FORF(i,1,N+1){
		if(isValid(i, grid, P[count].x, P[count].y)){
			grid[P[count].x][P[count].y] = i;

			if(sudokuBT(grid, P, num, count+1)) return true;

			grid[P[count].x][P[count].y] = 0;

		}
	}

	return false;
}

bool sudoku(int grid[N][N]){
	point *P = new point[N*N];
	int count = 0;
	FORF(i,0,N){
		FORF(j,0,N){
			if(grid[i][j]==0){ 
				P[count].x = i;
				P[count++].y = j;
			}
		}
	}

	return sudokuBT(grid, P, count);

}

int main(){
	int INP_SIZE;
	char str[N*N + 1];
	int grid[N][N];
	cin >> INP_SIZE;

	FORF(i,0,INP_SIZE){
		
		cin >> str;
		int CNT = 0;
		FORF(i,0,N){
			FORF(j,0,N){
				if(str[CNT] == '.') grid[i][j] = 0;
				else grid[i][j] = str[CNT]-'0';
				CNT++;
			}
		}
		
		cout << (sudoku(grid) ? "Y":"N") << endl;

		FORF(i,0,N){
			cout << endl;
			FORF(j,0,N){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
