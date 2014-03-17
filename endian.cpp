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

// check if your system is little or big endian
// little endian - last byte is stored first, big endian - first byte is stored first.
int main(){
	int val = 1;
	char *str = (char *)&val;

	if(*str) cout << "little Endian\n";
	else cout << "big Endian\n";

	return 0;
}
