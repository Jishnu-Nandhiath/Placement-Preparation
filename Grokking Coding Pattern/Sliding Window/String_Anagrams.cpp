#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

-------------------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given a string and pattern, find all anagrams of the pattern starting indices in the given string.

-------------------------------------------------------------------------------------------------------------------------------


This question is exactly similar to the last one, because in here instead of permutation boolean check, we're checking to find the
starting indices of the anagrams. So the only replacement is inside the matching where we add the windowStart values to the vector
instead of returning true in the last case.

Because in this case we need the indices of all the occurences instead of just confirming whether the input pattern got matched or not.

So we return the vector only after all the indices of occurences are retrieved. And the vector gets returned at the end of the execution.

*/

vector<int> findAnagramIndices(string inputString, string pattern){

	map<char,int> patternFrequencyMap;

	for(int i = 0; i < pattern.length(); i++){

		patternFrequencyMap[pattern[i]] += 1;
	
	}

	int windowSize = pattern.length();

	map<char,int> copyPatternMap = patternFrequencyMap;

	int matched = 0, windowStart = 0;

	vector<int> anagramIndices;

	for(int windowEnd = 0; windowEnd < inputString.length(); windowEnd++){

		if(patternFrequencyMap.find(inputString[windowEnd]) != patternFrequencyMap.end()){

			patternFrequencyMap[inputString[windowEnd]] -= 1;
			
			if(patternFrequencyMap[inputString[windowEnd]] == 0){
				matched += 1;
			}
		}


	if(matched == windowSize){
		anagramIndices.pb(windowStart);
	}

	if(windowEnd >= windowSize - 1){

		if(patternFrequencyMap.find(inputString[windowStart]) != patternFrequencyMap.end()){
			if(patternFrequencyMap[inputString[windowStart]] == 0){
				matched -= 1;
			}
			patternFrequencyMap[inputString[windowStart]] += 1;
		}
		windowStart += 1;
	}

	}

	return anagramIndices;

}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		string inputString, patternString;

		cin >> inputString >> patternString;

		print(findAnagramIndices(inputString,patternString));

	}

	return 0;
}