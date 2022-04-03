/*

Problem Statement:

Find the Maximum sum of contiguous subarray of given size in the input array.


*/


#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

int subArrayMaximumSum(vector<int> inputArray, int k){
	
	int windowMaxSum = 0, windowStart = 0, currentWindowSum = 0;
	for(int i = 0; i < inputArray.size(); i++){
		currentWindowSum += inputArray[i];

		if(i >= (k - 1)){
			windowMaxSum = max(windowMaxSum, currentWindowSum);
			currentWindowSum -= inputArray[windowStart];
			windowStart += 1;
		}
	}

	return windowMaxSum;
}





int32_t main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	/* input format:

	1 : No of Test Caes , next n test case contains 2 lines each.
	3 : Sub Array Size
	1 2 3 4 5 6 7 8 9 : Input Array of any size

	*/

	string inputString;

	int T,k;

	cin >> T;

	while(T--){
		cin >> k;

		vector<int> inputVector;

		cin.ignore();

		getline(cin, inputString);

		stringstream inputStream(inputString);

		int arrayElement;

		while(inputStream >> arrayElement){
			inputVector.pb(arrayElement);
		}	

		print(inputVector);

		cout << subArrayMaximumSum(inputVector, k) << endl;
	}

	return 0;
}