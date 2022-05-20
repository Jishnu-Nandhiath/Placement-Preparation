#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;


/* 

------------------------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

-------------------------------------------------------------------------------------------------------------------------------------


This is a basic question involving 2 pointers, 

where 2 pointers iterate from both end of an array to find the target sum.

Since the array has been sorted, if the current indices sum is larger than target, the end
pointer need to reduce because the array value below the current end index has to be smaller than
the current value. Because the array is sorted.

And if it is smaller than the current target, the start pointer will move forward to find a larger
value.

pair is a c++ datatype used to hold 2 values of same type or different type.

*/



pair<int,int> findPair(vector<int> inputVector, int target){

	int start = 0;
	int end = inputVector.size() - 1;



	while(start < end){
		if(inputVector[start] + inputVector[end] > target){
			end -= 1;
		}else if(inputVector[start] + inputVector[end] < target){
			start += 1;
		}else{
			return pair<int,int>{start,end};
		}

	}

	return pair<int,int>{0,0};

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
		int inputElement;
		int target;

		vector<int> inputVector;

		cin >> size;

		for(int i = 0; i < size; i++){
			
			cin >> inputElement;
			
			inputVector.pb(inputElement);
			
		}

	cin >> target;

	pair<int,int> output = findPair(inputVector,target);

	cout << output.first << " " << output.second << endl;


	}

	return 0;
}