#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

/*

--------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

--------------------------------------------------------------------------------------------------------------------


The algorithm implementation is simple, first we use two pointers starting from both ends. The pointer starting from
zero, will try to find the first mismatched element. For a sorted array, while iterating from 0 every element will be
greater than the last element. So we will get the index in the variable low as the first index in which the condition 
is not matched, this is for the first for loop.


Similarly we will iterate a pointer from the end of the array to find the first mismatched element, such that when iterating
from the end of an array, every element will be smaller than the last element it passed. So if for any element the condition 
is not matched we will store that in the high variable.

Then we will find the max and min value in the subarray which we just got.


And then, we will move away from the subarray from bothends. For low we will find if there is any element that is larger than
the subarray minimum so that the low pointer is increased. 

Similarly if the high pointer meets another element that is smaller than the current subarrray high, the high pointer is 
increased.

*/



int solve(vector<int> inputVector){
	
	int low = 0, high = inputVector.size() - 1;

	while(low < inputVector.size() - 1 && inputVector[low] <= inputVector[low + 1]){
		low += 1;
	}

	if(low == inputVector.size() - 1){
		return 0;
	}


	while(high > 0 && inputVector[high] >= inputVector[high - 1]){
		high -= 1;
	}


	int subArrayMin = INT_MAX;
	int subArrayMax = INT_MIN;

	for(int i = low;  i <= high; i++){

		subArrayMin = min(subArrayMin, inputVector[i]);
		subArrayMax = max(subArrayMax, inputVector[i]);

	}

	while(low > 0 && inputVector[low - 1] > subArrayMin){
		low -= 1;
	}

	while(high < inputVector.size() - 1 && inputVector[high + 1] < subArrayMax){
		high += 1;
	} 

	return high - low + 1;

}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		int size, element;

		cin >> size;

		vector<int> inputVector;

		for(int i = 0; i < size; i++){

			cin >> element;

			inputVector.pb(element);
		
		}

		cout << solve(inputVector);

	}

	return 0;
}