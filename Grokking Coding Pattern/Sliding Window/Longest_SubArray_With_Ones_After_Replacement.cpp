#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

---------------------------------------------------------------------------------------------------------------------------------------

Problem Statement: 

Given an array containing 0s and 1s, if you are allowed to replace no more than 'k' 0s with 1s, find the length of longest contiguous
subarray having all 1s.


----------------------------------------------------------------------------------------------------------------------------------------

This problem is exactly same as the last problem of Longest_Substring_With_SameLetters_After_Replacment,
except in this case it is more easy.

Because in this problem, we just need to keep track of the ones, and all other characters are zeros.

==================================================================================================================

So that, we need to check only when the window contains more than k zero characters. So that the left end
characters can be removed. 

In the last problem, the most repeating character can be any character, because of this we need to check
whether the current character occurence is more than the no of occureneces of the last character. But in this
case only count of ones needs to be checked.

*/




int longestOneArrayLength(vector<int> inputVector, int k){
	int windowStart = 0, longestOneLength = 0;


	int oneCount = 0;

	for(int i = 0; i < inputVector.size(); i++){

		if(inputVector[i] == 1){
			oneCount += 1;
		}

		if(i - windowStart + 1 - oneCount > k){
			if(inputVector[windowStart] == 1){
				oneCount -= 1;}
			windowStart += 1;
		}

		longestOneLength = max(longestOneLength, i - windowStart + 1);
	}

	return longestOneLength;
}



int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){

		int k, vecSize;
		vector<int> inputVector;

		cin >> vecSize >> k;

		int inputElement;

		for(int i = 0 ; i < vecSize ; i++){

			cin >> inputElement;

			inputVector.pb(inputElement);
		}

		cout << longestOneArrayLength(inputVector,k) << endl;

	}

	return 0;
}