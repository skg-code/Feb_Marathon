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

int bitonic(int *arr, int n){
	int *bit = new int[n];
	int *inc = new int[n];
	int *dec = new int[n];
	FORF(i,0,n){
		bit[i] = 1;
		inc[i] = 1;
		dec[i] = 1;
	}
	
	int OPT = 1;
	FORB(i,n-1,-1){
		FORF(j,i+1,n){
			if(arr[j] > arr[i]){
				inc[i] = max(inc[i], inc[j] + 1);
				bit[i] = max(bit[i], bit[j] + 1);
			}	
			else if(arr[j] < arr[i]){
				dec[i] = max(dec[i], dec[j] + 1);
				bit[i] = max(bit[i], dec[j] + 1);
			}
		}
		OPT = max(bit[i], OPT);
	}
	return OPT;
}

int main(){
//	int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
//     	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
//	int arr[] = {12, 11, 40, 5, 3, 1};
	int arr[] = {80, 60, 30, 40, 20, 10};	
	
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << bitonic(arr, n) << endl;
	return 0;
}
