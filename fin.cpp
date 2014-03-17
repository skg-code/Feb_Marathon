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
#define DOMECOST 350000
#define EQUIPMENT 50000
#define MONTHLY 50000
#define MAINTENANCE 5000
#define ADVANCE 100000
#define TARGET_TIME 60
#define COMMISSION 20000
#define COACH_SALARY 15000
#define DD double

using namespace std;

DD base(int I, int N, int balance){
	return I*MONTHLY + N*ADVANCE + balance - I*COACH_SALARY;
}

DD func(DD I, DD In, DD balance, int N){
	if(N == 34) return I;
	
	DD newI = floor( base(I, In, balance) /(DOMECOST+EQUIPMENT+COMMISSION) );
	
	return func(I + newI, newI, ((int)base(I, In, balance))%(DOMECOST+EQUIPMENT+COMMISSION), N+1);
}

int funcIN(DD I, DD In, DD balance, int M){
	if(M == TARGET_TIME) return I;
	
	if(M%12 == 0)cout << I << " " << In << endl;	
	
	DD newI = floor( base(I, In, balance) /(DOMECOST+EQUIPMENT+COMMISSION) );

	return funcIN(I + newI, newI, ((int)base(I, In, balance))%(DOMECOST+EQUIPMENT+COMMISSION), M+1);
}

DD revenue(DD rev, DD I, DD In, DD balance, int M){
	if(M == TARGET_TIME) return rev;
	
	DD newI = floor( base(I, In, balance) /(DOMECOST+EQUIPMENT+COMMISSION) );
	
//	cout << "month "<< M << ": Revenue " << (long long)I*MONTHLY << ": New arenas " << In << endl;
	if(M%12==0) cout << (long long)rev << endl;
	return revenue(rev + I*COACH_SALARY, I + newI, newI, ((int)base(I, In, balance))%(DOMECOST+EQUIPMENT+COMMISSION), M+1);
}


long long seedCap(int yTarget){
	return revenue(0, yTarget, yTarget, 0, 0);
/*	int i = 0;
	while(1){
		DD out = func(++i, i, 0, 0);
		if(out >= yTarget) return i;
	}
*/	
}

int main(){
	int INPUT;
	cout << "Input number of arenas to start with : ";
	cin >> INPUT;
	cout << endl << TARGET_TIME/12 << " years : " << seedCap(INPUT) << endl;	
	return 0;
}
