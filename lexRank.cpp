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

#define FORF(i,a,b) for(int i = a; i != b; i++)
#define FORB(i,b,a) for(int i = b; i != a; i--)
#define AL 26

int fact(int N){
	return (N > 1 ? N*fact(N-1) : 1);
}

int lexRank(char *str, int I, int N){
	if(I == N) return 1;

	int count = 0;
	for(int i = I+1; i < N; i++){
		if(str[i] < str[I]) count++;	
	}

	return count*fact(N-1-I) + lexRank(str, I+1, N);	
}

// Given a string, find the lexicographical rank of the string.
int lexRankL(char *str){
	int len = strlen(str);
	int *arr = new int[AL];
	memset(arr, 0, sizeof(arr));

	FORF(i,0,len){
		arr[ str[i] - 'a' ] = 1;
	}
	
	int count = 0;
	FORF(i,0,AL){
		if(arr[i]==1){
			arr[i] = count;
			count++;
		}
	}
	
	int res = 0;
	FORF(i,0,len){
		res += (arr[ str[i] - 'a' ]*fact(len-i-1));
		
		FORF(j,str[i]-'a'+1,AL){
			arr[j]--;
		}
	}

	return res+1;
}

int main(){
	char str[20];
	scanf("%s",str);
	cout << lexRank(str, 0, strlen(str)) << endl;
	cout << lexRankL(str) << endl;
	return 0;
}
