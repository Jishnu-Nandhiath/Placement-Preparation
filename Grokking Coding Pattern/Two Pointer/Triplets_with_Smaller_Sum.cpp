#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

---------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given an array of arr of unsorted numbers and a target sum, count all triplets in it such that the triplet total sum
is less than the given target. Write a function to return the count of such triplets.

---------------------------------------------------------------------------------------------------------------------

In this question we need to find the triplets whose sum is less than that of the given target.

So this is a similar 2 pointer apporach to other similar triplet questions.

The interesting part of this question is whenever you find a triplet having sum less than that of the target, then
all other numbers between the right and left pointers can also make up that triplet satisfying the condition. 

Because since the array is sorted,

arr[left] <= arr[right]

And in this solution we haven't taken care of duplicates, We assume that the input vector is of unique elements.


*/




int smallerSumTriplets(vector<int> inputVector, int target){
	
	int count = 0;

	sort(inputVector.begin(),inputVector.end());

	for(int i = 0; i < inputVector.size() - 2; i++){

		int left = i + 1, right = inputVector.size() - 1;

		while(left < right){

			int targetSum = inputVector[left] + inputVector[right] + inputVector[i];

			if(targetSum < target){

				count += right - left;
				left += 1;

			}else{

				right -= 1;
			
			}

		}
	}

	return count;
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){

		int target, vectorElement, vectorSize;

		cin >> vectorSize >> target;

		vector<int> inputVector;

		for(int i = 0; i < vectorSize; i++){
			cin >> vectorElement;
			inputVector.pb(vectorElement);
		}

		cout << smallerSumTriplets(inputVector,target) << endl;
	
	}

	return 0;
}