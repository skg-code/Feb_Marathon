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

// Given list of words, print those, which contain the given word as a substring.
// works only for words having unique chars.
void print(char *list[], char *word, int N){
	int *mp = new int[AL];
	int len = strlen(word);
	FORF(i,0,len) mp[ word[i] - 'a' ] = N;

	FORB(i,N-1,-1){
		int L = strlen(list[i]);
		int count = 0;
		FORF(j,0,L){
			if(mp[ list[i][j] - 'a' ] > i){
				mp[ list[i][j] - 'a' ] = i;
				count++;
				if(count == len){
					cout << list[i] << endl;
					break;
				}
			}
		}
	}
}

int main(){
	char str[] = "sun";
	char *list[] = {"geeksforgeeks", "unsorted", "sunday", "just", "sss" , "utensils"};
	print(list, str, 6);
	return 0;
}
