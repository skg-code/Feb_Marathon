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


// an array of sqn+1 length is created. each contains index for min[arr[i*sqn],arr[i*sqn + 1]).
void buildSQN(int *subArr, int sqn, int *arr, int N){
	FORF(i,0,sqn+1){
		int mn = i*sqn;
		for(int j = i*sqn; j != (i+1)*sqn && j != N; j++){
			mn = (arr[j] < arr[mn] ? j : mn);
		}
		subArr[i] = mn;
	}
}

// Range minimum query. Given a range , find index of the smallest number in that.
void RMQ(int *arr, int N, int *subArr, int sqn, int start, int end){
	int mn = start;
	FORF(i,0,sqn+1){
		if(start <= i*sqn && end >= (i+1)*sqn - 1){
			mn = (arr[ subArr[i] ] < arr[mn] ? subArr[i] : mn);
		}
		else if(start > i*sqn || end < (i+1)*sqn - 1){
			for(int j = max(start, i*sqn); j < min(end+1, (i+1)*sqn); j++){
				mn = (arr[j] < arr[mn] ? j : mn);
			}
		}
	}

	cout << mn << " " << arr[mn] << endl;

}

int main(){
	int arr[] = {2,4,3,11,6,7,8,9,1};
	int N = sizeof(arr)/sizeof(arr[0]);
	int sqn = (int) sqrt(N);

	int *subArr = new int[sqn+1];
	buildSQN(subArr, sqn, arr, N);

	RMQ(arr, N, subArr, sqn, 1, 8);

	return 0;
}
