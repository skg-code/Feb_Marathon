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

// find the number of occurrences of '2' between 0,n
int count2(int n, long P, int p, int *AP){
	if(n<=1) return 0;
	
	return ( n%P >= 2*(P/10) )*10 + (n/P)*AP[p] + count2(n%P, P/10, p-1,  AP);
}

int num2(int n){
	
/*	int ctr=0;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j>0;j=j/10)
		{
			if((j%10)==2)
				ctr++;
		}

	}

	return ctr;
*/

	
	int AP[] = {0,1,20,300,4000,50000,600000,7000000,80000000};


	return count2(n, 10000000, 7, AP);


}

int main(){
	cout << 1 << " " << num2(1) << endl;
	cout << 10 << " " << num2(10) << endl;
	cout << 100 << " " << num2(100) << endl;
	cout << 1000 << " " << num2(1000) << endl;
	cout << 10000 << " " << num2(10000) << endl;
	cout << 100000 << " " << num2(100000) << endl;
	cout << num2(32) << endl;
	return 0;
}
