#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a ) {for(auto y : x){ cout << y << " "; }cout << endl;} cout << endl;

using namespace std;


/*

This is a naive solution.

First we're iterating through the input array list. We need three numbers to complete an array list. Instead of O(N*3)
We've achieved around O(N*2) with the 2 pointer approach.

First we take an input element and then used the 2 pointers to iterate across the input list to find the other 2 elements
that are adding upto the -ve target.

Since unique triplets are required, we can sort the array to skip the duplicate elements by comparing the adjacent elements.

This is also done using 3 if conditions inside the loops.

*/


vector<vector<int>> tripletSumZero(vector<int> inputVector){

	vector<vector<int>> triplets;

	sort(inputVector.begin(), inputVector.end());

	for(int i = 0; i < inputVector.size(); i++){

		int start = i + 1, end = inputVector.size() - 1;

		if(inputVector[i - 1] == inputVector[i] && i > 0)
			continue;

		int target = -inputVector[i];

		while(start < end){

			int targetSum = inputVector[start] + inputVector[end];

			if(targetSum == target){

				triplets.pb({inputVector[start],inputVector[end],-target});
				start += 1;
				end -= 1;

			}else if(targetSum > target){

				end  -= 1;

			}else{

				start += 1;

			}

			if(inputVector[start + 1] == inputVector[start])
				start += 1;
			if(inputVector[end - 1] == inputVector[end])
				end -= 1; 

		}


	}

	return triplets;


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

		for(int i = 0; i < size; i++){

			cin >> inputElement;

			inputVector.pb(inputElement);
		}

		print2(tripletSumZero(inputVector));

	}

	return 0;
}