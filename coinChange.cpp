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

int coinChange(int *, int, int);

// given N, find number of combinations of coin denominations that add upto N
int coinChange(int *arr, int N, int sum){
	int index[sum+1][N];
	FORF(i,0,N) index[0][i] = 1;

	FORF(i,1,sum+1){
		FORF(j,0,N){
			index[i][j] = (i-arr[j] >= 0 ? index[i-arr[j]][j]:0) + (j>=1 ? index[i][j-1]:0);//include & exclude cases respectively
		}
	}

	return index[sum][N-1];

}

int main(){
	int arr[] = {1,2,3};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout << coinChange(arr, N, 4) << endl;
	return 0;
}
