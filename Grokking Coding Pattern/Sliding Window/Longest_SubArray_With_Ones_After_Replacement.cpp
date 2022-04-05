#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

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