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

#define FOR(i,a,n) for(int i=a;i!=n;i++)
#define LL long long


void bucketSort(int *, int);
LL recMul(int *, int, int);
string remMul(int *, int);
string largMul(int *, int);
string merge(stack<int> *,stack<int> *,stack<int> *);

void bucketSort(int *arr, int N){
	int RAD[10]={0};
	for(int i=0; i!=N; i++){
		RAD[ arr[i] ]++;
	}
	int index = 0;
	for(int i=9; i!=-1; i--){
		for(int j=0; j!=RAD[i]; j++){
			arr[index++] = i;	
		}
	}
	return;
}

LL recMul(int *arr, int N, int index = 0, int sum = 0, LL mul = 0){
	if(index == N && sum%3 == 0) return mul;
	if(index == N) return -1;

	LL mul1 = recMul(arr, N, index+1, sum + arr[index], mul*10 + arr[index]);
	if(mul1 != -1) return mul1;
	
	return recMul(arr, N, index+1, sum, mul);

}

string remMul(int *arr, int N){
	stack<int> *S0 = new stack<int>;
	stack<int> *S1 = new stack<int>;
	stack<int> *S2 = new stack<int>;

	int sum = 0;
	FOR(i,0,N){
		sum += arr[i];
		if(arr[i]%3 == 1) S1->push(arr[i]);
		else if(arr[i]%3 == 2) S2->push(arr[i]);
		else S0->push(arr[i]);
	}

	if(sum%3 == 1){
		if(S1->size() > 0) S1->pop();
		else if(S2->size() > 2){
			S2->pop();
			S2->pop();
		}
		else return "";
	}
	else if(sum%3 == 2){
		if(S2->size() > 0) S2->pop();
		else if(S1->size() > 2){
			S1->pop();
			S1->pop();
		}
		else return "";
	}
	
	return merge(S0, S1, S2);
}

string merge(stack<int> *S0, stack<int> *S1, stack<int> *S2){
	int bucket[10]={0};
	stringstream result;
	while(S0->size() > 0){
		bucket[ S0->top() ]++;
		S0->pop();
	}
	
	while(S1->size() > 0){
		bucket[ S1->top() ]++;
		S1->pop();
	}
	
	while(S2->size() > 0){
		bucket[ S2->top() ]++;
		S2->pop();
	}
	
	for(int i = 9; i != -1; i--){
		FOR(j,0,bucket[i]){
			result << i;
		}
	}
	return result.str();
}


// Largest number possible from the array, which is divisible by 2,3,5
string largMul(int *arr, int N){
	bucketSort(arr, N);	
//	return recMul(arr, N);
	return remMul(arr, N);
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	cout << largMul(arr, sizeof(arr)/sizeof(arr[0])) << endl;
	return 0;
}
