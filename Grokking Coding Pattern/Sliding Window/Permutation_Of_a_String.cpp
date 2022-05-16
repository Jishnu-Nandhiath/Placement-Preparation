#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << " , "; cout << endl;

using namespace std;

bool isPermutation(string inputString, string pattern){

	map<char,int> patternFrequencyMap;

	int window = pattern.size();

	for(int i = 0; i < window; i++){
		patternFrequencyMap[pattern[i]] += 1;
	}

	int windowStart = 0;

	for(int windowEnd = 0; windowEnd < inputString.length(); windowEnd++){

		if(patternFrequencyMap.size() == 0)
			return true;

		print1(patternFrequencyMap);


		if(patternFrequencyMap.find(inputString[windowEnd]) != patternFrequencyMap.end()){

			patternFrequencyMap[inputString[windowEnd]] -= 1;

			if(patternFrequencyMap[inputString[windowEnd]] == 0){

				patternFrequencyMap.erase(inputString[windowEnd]);

			}
		}

		if(windowEnd - windowStart + 1 > window){

			if(pattern.find(inputString[windowStart]) < pattern.length()){
				patternFrequencyMap[inputString[windowStart]] += 1;
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
			cout << "True" << endl;
		else
			cout<<"False" << endl;

	}

	return 0;
}