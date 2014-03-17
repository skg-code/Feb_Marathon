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

// given an array, find elements that add up to SUM.
bool subSetSumBT(int *arr, int *subArr, int N, int SUM, int k, int sum=0){
	if(sum == SUM) 	return true;
	if( k >= N || sum > SUM) return false;

	*subArr = *arr;
	if(subSetSumBT(arr+1, subArr+1, N, SUM, k+1, sum + *arr)) return true;

	return subSetSumBT(arr+1, subArr, N, SUM, k+1, sum);
}

int main(){
	int arr[] = {10, 7, 5, 18, 12, 20, 15};
	int N = sizeof(arr)/sizeof(arr[0]);
	int subArr[N];
	if(subSetSumBT(arr, subArr, N, 35, 0)){
		for(int i=0,sum=0; i!=N && sum<=35; i++,sum+=subArr[i]){
			cout << subArr[i] << endl;
		}
	}
	return 0;
}
