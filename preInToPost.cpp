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

#define FOR(i,a,n) for(int i=a;i!=n;i++)

using namespace std;

// Given Infix, prefix. Find postfix.
void preInToPost(int *in, int ina, int inb, int *pre, int prea, int preb, stack<int> *S){
	if(prea > preb) {
		return ;
	}

	for(int i = ina; i != inb+1; i++){
		if(in[i] == pre[prea]){
			S->push(in[i]);
			preInToPost(in, i+1, inb, pre, prea+(i-ina)+1, preb, S);
			preInToPost(in, ina, i-1, pre, prea+1, prea+(i-ina), S);
			break;
		}
	}

	return ; 
}

void printStack(stack<int> *S){
	while(S->size()){
		cout << S->top() << " ";
		S->pop();
	}
	cout << endl;
}

int main(){
	
	int in[] = {4,2,5,1,3,6};
	int pre[] = {1,2,4,5,3,6};
	stack<int> *S = new stack<int> ;
	preInToPost(in,0,5,pre,0,5,S);
	printStack(S);
	return 0;
}
