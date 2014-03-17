#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

void computeLPS(char *str,int *lps,int n){
	lps[0] = 0;
	int len = 0;
	int i = 1;

	while(i!=n){
		if(str[i]==str[len]){
			len++;
			lps[i] = len;
			i++;
		}
		
		else{
			if(len){
				len = lps[len-1];
			}
			else{
				lps[i] = len;
				i++;
			}
		}
	}
}


// compute max period in a string, if any.
bool checkPeriod(char *str){
	int len = strlen(str);
	
	int *lps = new int[len];
	computeLPS(str,lps,len);
	
	int maxP = 0;
	for(int i=0;i!=len;i++){
		if(lps[i] && (i+1)%lps[i]==0 && (i+1)/lps[i]==2) maxP = max(maxP,lps[i]);	
	}
	
	if(!maxP) return false;
	for(int i=0;i+maxP!=len;i++){
		if(str[i]!=str[i+maxP]) return false;
	}
	cout << "period is " << maxP << endl;
	
	return true;
}

int main(){
	char *str = new char[100];
	while(1){
		cout << "Input : ";
		cin >> str;
		cout << endl;
		cout << (checkPeriod(str)?"true":"false") << endl;
		cout << endl;
	}
	return 0;
}
