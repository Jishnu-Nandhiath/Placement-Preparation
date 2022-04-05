#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

bool isPermutation(string inputString, string pattern){

	vector<char> patternVector(pattern.begin(),pattern.end());

	int windowSize = pattern.size();

	int windowStart = 0;

	for(int i = 0; i < inputString.size(); i++){

		if(patternVector.size() == 0){
			return true;
		}

		cout << inputString[i];

		// print(patternVector);

		if(find(patternVector.begin(),patternVector.end(),inputString[i]) != patternVector.end()){
			cout << 1;
			patternVector.erase(patternVector.begin() + i);
		}

		if( i - windowStart + 1 > windowSize){
			// cout<<2;
			if(find(patternVector.begin(),patternVector.end(),inputString[windowStart]) != patternVector.end()){
				patternVector.pb(inputString[windowStart]);
			}
			windowStart += 1;
		}

	}

	return false;

}



int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
		
		string inputString, pattern;

		cin >> inputString >> pattern;

		if(isPermutation(inputString,pattern) == true)
			cout << "true" << endl;
		else
			cout<<"hi";

	}

	return 0;
}