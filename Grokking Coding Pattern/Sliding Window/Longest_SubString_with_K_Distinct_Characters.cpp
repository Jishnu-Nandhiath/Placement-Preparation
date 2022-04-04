#include<bits/stdc++.h>

// #define int long long int
#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;


int longestStringWithGivenDistinctCharacters(string inputString, int k){

	int longestStringLength = 0, windowStart = 0;

	map<char,int> stringCharCount;

	int length = inputString.size();	

	for(int i = 0; i < length; i++){

		if(stringCharCount.find(inputString[i]) != stringCharCount.end()){
			stringCharCount[inputString[i]] += 1;

		}else{
			stringCharCount[inputString[i]] = 1;
		}


		// cout << inputString[i] << " " << stringCharCount[inputString[i]] << endl;

		while(stringCharCount.size() > k){
			longestStringLength = max(longestStringLength, i - windowStart);
			stringCharCount[inputString[windowStart]] -= 1;
			if(stringCharCount[inputString[windowStart]] == 0){
				stringCharCount.erase(inputString[windowStart]);
			}
			windowStart += 1;
		}
	}

	return longestStringLength;

}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T, k ;

	string inputString;

	cin >> T;

	while(T--){
		
		cin >> k;

		cin.ignore();

		getline(cin, inputString);

		cout << longestStringWithGivenDistinctCharacters(inputString, k) << endl;

	}

	return 0;
}