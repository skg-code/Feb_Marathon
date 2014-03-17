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

typedef struct SF{
	int start;
	int finish;
}SF;

int compare(const void *A, const void *B){
	int dif1 = (((SF *)A)->finish - ((SF *)B)->finish);
	int dif2 = (((SF *)A)->start - ((SF *)B)->start);
	return (dif1 == 0 ? dif2 : dif1);	
}

// Given start & finish times of diff. activities, find the optimal number of activities possible.
int activitySelection(SF *sf, int N){
	int res = 0;
	int T = 0;
	FORF(i,0,N){
		if(sf[i].start >= T){
			res++;
			T = sf[i].finish;
		}
	}
	return res;
}

int main(){
	SF sf[] = {{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};
	int N = sizeof(sf)/sizeof(sf[0]);
	
	qsort(sf, N, sizeof(sf[0]), compare);
	
	FORF(i,0,N){
		cout << sf[i].start << " " << sf[i].finish << endl;
	}
	
	cout << "Activities possible : " << activitySelection(sf, N) << endl;

	return 0;
}
