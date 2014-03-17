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

// check if two strings are interleaved
void interlStr(char *init, char *str, char *A, char *B){
	if(*A == '\0' && *B == '\0'){
		*str = '\0';
		cout << init << endl;
		return;
	}

	if(*A != '\0'){
		*str = *A;
		interlStr(init, str+1, A+1, B);
	}

	if(*B != '\0'){
		*str = *B;
		interlStr(init, str+1, A, B+1);
	}
}

int main(){
	char A[] = "AB";
	char B[] = "CD";
	char res[10];
	
	interlStr(res, res, A, B);

	return 0;
}
