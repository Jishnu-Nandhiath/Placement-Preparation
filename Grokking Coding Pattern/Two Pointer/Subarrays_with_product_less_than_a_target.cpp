#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a) { for(auto y : x) cout << y << " "; cout << endl; } cout << endl;

using namespace std;


/*

-----------------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given an array with positive numbers and a target number, find all of its contiguous subarrays whose product is less than
the target number.

-----------------------------------------------------------------------------------------------------------------------------

In here, we're keeping track of the product, and when the product gets more than the desired value we're trying to 
reduce it. So this problem is most likely a combination of sliding window and the 2 pointer approach.

The sliding window is dynamic where whenever the current product value exceeds the while loop is reducing the size of
the window, and moving from left to right.

And outside the sliding window, another pointer is adding the elements to the result list. As a nested list. Since, the
elements producing a higher sum is already removed by the sliding window. The second pointer can add the elements to the 
list consecutively. 

Since the contiguous subarrays need to be returned, we're using a deque to use the append left functionality to keep the 
order while adding the elements to the result list.


*/



vector<vector<int>> findProductsLessThanTarget(vector<int> inputVector, int target){

	int product = 1;

	int left = 0;

	vector<vector<int>> productValues;

	deque<int> temp;

	for(int right = 0; right < inputVector.size(); right++){

		product *= inputVector[right];

		while(product >= target && left < inputVector.size()){

			product /= inputVector[left];
			left += 1;

		}


		temp.clear();

		for(int i = right; i > left - 1; i--){

			temp.push_front(inputVector[i]);

			vector<int> nestedVector(temp.begin(),temp.end());

			productValues.pb(nestedVector);
		}

	}

	return productValues;

}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){

		int size, target;

		cin >> size >> target;

		int inputElement;

		vector<int> inputVector;

		for(int i = 0; i < size; i++){
			cin >> inputElement;
			inputVector.pb(inputElement);		
		}

		print2(findProductsLessThanTarget(inputVector,target));
	
	}

	return 0;
}