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

typedef struct tree{
	char ch;
	int freq;
	struct tree *left;	
	struct tree *right;	
}tree;

bool comp(const tree* L, const tree *R){
	return (L->freq > R->freq);
}

void HeapV(vector<tree *> &V, int size, char *arr, int *freq){
	FORF(i,0,size){
		tree *tr = new tree;
		tr->ch = arr[i];
		tr->freq = freq[i];
		tr->left = NULL;
		tr->right = NULL;
		
		V.push_back(tr);
	}
	make_heap(V.begin(), V.end(), comp);
}

void huffCode(tree *tr, string str){
	if(!tr) return;
	if(tr->ch != '!') cout << tr->ch << " " << str << endl;
	
	huffCode(tr->left, str+'0');	
	huffCode(tr->right, str+'1');	
}

void prinTree(tree *tr){
	if(!tr) return;

	cout << tr->ch << " " << tr->freq << endl;

	prinTree(tr->left);
	prinTree(tr->right);
}

// Given frequency of occurrences of chars, encode them in binary using huffman coding technique.
void huffmanCoding(vector<tree *> &V, int size){
	while(V.size() != 1){
		tree *tr1 = V.front(); pop_heap(V.begin(), V.end(), comp); V.pop_back();
		tree *tr2 = V.front(); pop_heap(V.begin(), V.end(), comp); V.pop_back();

		tree *tr = new tree;
		tr->freq = tr1->freq + tr2->freq;
		tr->ch = '!';
		tr->left = tr1;
		tr->right = tr2;

		V.push_back(tr); push_heap(V.begin(), V.end(), comp);
	}
	
	huffCode(V.front(), "");
}

int main(){
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	vector<tree *> V;
	HeapV(V, size, arr, freq);
	
	huffmanCoding(V, size);

	return 0;
}
