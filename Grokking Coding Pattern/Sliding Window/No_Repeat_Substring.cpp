#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

int longestNoRepeatString(string inputString){
	int windowStart = 0, uniqueStringLength = 0;
	
	map<char,int> charIndex;

	char currChar;
	
	for(int i = 0; i < inputString.size(); i++){
		currChar = inputString[i];

		if(charIndex.find(currChar) != charIndex.end()){
			windowStart = max(windowStart, charIndex[currChar] + 1);
		}
		charIndex[inputString[i]] = i;
		uniqueStringLength = max(uniqueStringLength, i - windowStart + 1);
	}	
	return uniqueStringLength;
}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	string inputString;

	// cout << "hi";

	while(T--){


		cin >> inputString;	

		// cout << inputString;
		cout << inputString <<" : " << longestNoRepeatString(inputString) << endl;
	}

	

	return 0;
}