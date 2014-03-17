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

// print spiral path of a tree
void print_spiral(stack *S1,stack *S2,bool fl){
	if(S1.empty() && S2.empty()) return;
	while(!S1.empty()){
		if(!fl){
			tree *tr = S1.top();
			print(tr->node);
			S1.pop();
			S2.push(tr->left);
			S2.push(tr->right);	
		}
		else{
			tree *tr = S1.top();
			print(tr->node);
			S1.pop();
			S2.push(tr->right);
			S2.push(tr->left);	
		}
	}
	print_spiral(S2,S1,!fl);
	return ;
}

int main(){
	stack *S1;
	stack *S2;
	node *tree;
	S1.push(tree);
	print_spiral(S1,S2,0);	
	return 0;
}
