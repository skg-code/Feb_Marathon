#include<iostream>

using namespace std;

// given an array where every element occurs 3 times, find a number that occurs just once. 
int findOdd(int *arr,int n){
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

	for(int i = 0;i!=n;i++){
		D = ~B;

		D = arr[i] & D;	
		
		C = B & arr[i];

		B = C^B;
		
		B = B | (A & arr[i]);
		
		A = A^D;
	}
	return A;
}

int main(){
	int arr[] = {12,12,3,12,28,3,3};
	cout << findOdd(arr,7) << endl;
	return 0;
}
