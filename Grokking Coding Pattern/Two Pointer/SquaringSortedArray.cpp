#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

-------------------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given a sorted array, create a new array containing squares of all the number of the input array in the sorted order.

-------------------------------------------------------------------------------------------------------------------------------

The tricky part of the below question is the vector can have both -ve and +ve elements,

If the array contains negative numbers, the sorted array start with negative numbers, since we need to maintain the sort after
squaring each element. We can't consecutively square each element. Because squaring negative numbers will result in positive numbers.

This is the reason for implementation of 2 pointer algorithm.

*/



vector<int> squareSortedArray(vector<int> inputVector){

	int start = 0;
	int end = inputVector.size() - 1;

	vector<int> outputVector;

	// outputVector.resize(inputVector.size());

	while(start <= end){
		if(abs(inputVector[start]) > abs(inputVector[end])){
			outputVector.pb(pow(inputVector[start], 2));
			start += 1;
		}else{
			outputVector.pb(pow(inputVector[end], 2));
			end -= 1;
		}
	}

	return outputVector;

}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		int size;

		cin >> size;

		int inputElement;
		vector<int> inputVector;

		while(size--){
			cin >> inputElement;
			inputVector.pb(inputElement);
		}

		print(squareSortedArray(inputVector));

	}

	return 0;
}