/*

Problem Statement:

Return the size of the smallest contiguous subarray whose sum is greater or equal to the given value. 

*/

#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

int smallestSubArrayWithGivenSum(vector<int> inputVector, int S){

	int windowSize = INT_MAX, windowSum = 0, windowStart = 0, currWindowSize = 0;

	for(int i = 0 ; i < inputVector.size(); i++){
		windowSum += inputVector[i];

		while(windowSum >= S){
			currWindowSize = i - windowStart + 1;
			windowSize = min(windowSize, currWindowSize);
			windowSum -= inputVector[windowStart];
			windowStart += 1;
		}

	}

	return windowSize;
}


int32_t main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		int S;

		vector<int> inputVector;

		cin >> S;

		cin.ignore();

		string inputArrayString;

		getline(cin, inputArrayString);

		stringstream inputStream(inputArrayString);

		int arrayElement;

		while(inputStream >> arrayElement){
			inputVector.pb(arrayElement);
		}


	cout << smallestSubArrayWithGivenSum(inputVector, S) << endl;

	}

	return 0;
}