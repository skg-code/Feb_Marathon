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

int makeEqual(string &F,string &S){
	int len1 = F.size();
	int len2 = S.size();

	if(len1 > len2){
		for(int i = 0;i != len1-len2;i++) S = '0'+S;
		return len1;
	}
	else if(len2 > len1){
		for(int i = 0;i != len2-len1;i++) F = '0'+F;
	}
	return len2;
}

string addString(string F,string S){
	int len = makeEqual(F,S);
	int carry = 0;
	string result;
	for(int i = len-1;i!=-1;i--){
		int fb = F.at(i) - '0';
		int sb = S.at(i) - '0';
		int sum = (fb^sb^carry)+'0';
		result = (char) sum + result;
		carry = ((fb&sb) | (sb&carry) | (fb&carry));
	}
	if(carry) result = '1' + result;
	return result;
}

int mulBit(string m1,string m2){
	return (m1[0]-'0')*(m2[0]-'0');
}

// karastuba multiplication technique
int mulStr(string F,string S){
	int len = makeEqual(F,S);
	if(len == 0) return 0;
	if(len == 1) return mulBit(F,S);

	int lt = len/2;	
	int rt = len - lt;

	string x1 = F.substr(0,lt);	
	string x2 = F.substr(lt,rt);	

	string y1 = S.substr(0,lt);	
	string y2 = S.substr(lt,rt);

	int p1 = mulStr(x1,y1);		
	int p2 = mulStr(x2,y2);
	int p3 = mulStr(addString(x1,x2),addString(y1,y2));
	
	return p1*(1<<2*rt) + p2 + (p3 - p2 - p1)*(1<<rt);	
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	cout << mulStr(s1,s2) << endl;
	
	return 0;
}
