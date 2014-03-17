#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime> 

using namespace std;

#define RANGE 10

#define FOR(i,a,b) for(int i=a; i!=b; i++)

int* count_sort(int *temp,int *arr,int n){
	int *ret;
	ret = new int[n];
	
	int rA[RANGE];
	memset(rA,0,sizeof(rA));
	
	FOR(i,0,n){
		rA[ temp[i] ]++;
	}
	
	int count = 0;
	FOR(i,0,RANGE){
		count += rA[i];
		rA[i] = count;
	}

	for(int i=n-1; i!=-1; i--){
		ret[ rA[ temp[i] ] - 1 ] = arr[i];
		rA[ temp[i] ]--;
	}

	return ret;
}

int* radix_sort(int *arr,int n){

	int *temp;
	temp = new int[n];
	
	int sum;
	int k;
	int pow = 1;

	do{
		sum = 0;
		FOR(i,0,n){
			temp[i] = arr[i] / pow;
			
			sum += temp[i]/10;
			
			temp[i] %= 10;
		}
		
		pow *= 10;
		arr = count_sort(temp, arr, n);
	}while(sum);

	return arr;
}

int main(){
	int n;
	cin >> n;
	
	int *arr;
	arr = new int[n];

	FOR(i,0,n){
		cin >> arr[i];
	}
	
	cout << endl;
	arr = radix_sort(arr, n);

	FOR(i,0,n) cout << arr[i] << " ";

	cout << endl;

	return 0;
}
