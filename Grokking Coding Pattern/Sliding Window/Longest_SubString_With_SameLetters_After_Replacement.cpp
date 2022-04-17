#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;



int longestSubstringWithSameLetters(string inputString, int k){

	int windowStart = 0, largestStringLength = 0, maxCountRepatingChars = 0;

	char rightChar, leftChar;


	map<char,int> frequencyMap;

	for(int i = 0; i < inputString.size(); i++){
		rightChar = inputString[i];

		if(frequencyMap.find(rightChar) == frequencyMap.end()){
			frequencyMap[rightChar] = 0;
		}
		frequencyMap[rightChar] += 1;

		maxCountRepatingChars = max(maxCountRepatingChars, frequencyMap[rightChar]);

		if(i - windowStart + 1 - maxCountRepatingChars > k){
			leftChar = inputString[windowStart];
			frequencyMap[leftChar] -= 1;
			windowStart += 1;
		}

		largestStringLength = max(largestStringLength, i - windowStart + 1);
	}

	return largestStringLength;

}



int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){

		int k;
		string inputString;

		cin >> k;
		cin >> inputString;

		// cout << k;

		cout << inputString << " : " << longestSubstringWithSameLetters(inputString, k) << endl;
	}

	return 0;
}