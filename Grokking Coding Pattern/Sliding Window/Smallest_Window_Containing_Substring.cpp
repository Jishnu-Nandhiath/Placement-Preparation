#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*
The problem is a dynamic sliding window pattern type.

Where we need to find the smallest substring containing all the occurence of the pattern.

This question is also similar to permutation and anagrams. Except the case is that, substring need not be contiguos, so
there may be unwanted characters in the substring window we're operating on. So we need to take care of this as well.

So, some modification in this problems are 

1. the matched integer variable will keep track of the count of matches instead of the no of unique characters.
	This is because in this case, there may be duplicate characters of the pattern characters that we don't want to
	match, so that we also need to consider that case.

	So instead of increasing the complexity with additional if checks, we are just allowing the dictionary key value
	to go negative, and matched to keep the count of all characters. So that if a match has been occured and the key value
	is non negative, then it's a positive match for character inside pattern in the current window.

	This explains why the matched has increased to the count of character occurence and dictionary values to go negative.

	So that when the windowStart pops out the characters inside the window, the negative values will automatically becomes
	positive. 

2. And the while loop is added because once a match is found, we can remove the unwanted characters at the start of the window
	to see whether the condition still matches, because we need the smallest count.

3. The if loop to change the window Size is implemented inside the while loop, because we don't need to change the window size
	until the pattern got matched. So it's there, no other reason.

*/


string smallestSubstringWindow(string inputString, string pattern){

	map<char,int> patternFrequencyMap;

	for(int i = 0; i < pattern.length(); i++){

		patternFrequencyMap[pattern[i]] += 1;
	
	}

	int windowStart = 0, matched = 0;

	string output;

	int smallestWindow = inputString.length();

	for(int windowEnd = 0; windowEnd < inputString.length(); windowEnd++){

		if(patternFrequencyMap.find(inputString[windowEnd]) != patternFrequencyMap.end()){

				patternFrequencyMap[inputString[windowEnd]] -= 1;	
		

			if(patternFrequencyMap[inputString[windowEnd]] >= 0){
				matched += 1;
			}
		}



		while(matched == pattern.length()){

			if(smallestWindow > windowEnd - windowStart + 1){
				
				smallestWindow = windowEnd - windowStart + 1;

				output = inputString.substr(windowStart, smallestWindow);
			}

			// cout << "windowStart : " << windowStart << " windowEnd : " << windowEnd <<"  output : " << output << endl;

			if(patternFrequencyMap.find(inputString[windowStart]) != patternFrequencyMap.end()){
				
				if(patternFrequencyMap[inputString[windowStart]] == 0){
					matched -= 1;
				}

				patternFrequencyMap[inputString[windowStart]] += 1;

			}

			windowStart += 1;

		}


		// cout << windowStart << endl;

	

	}
	return output;

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

	cout << smallestSubstringWindow(inputString,pattern) << endl;


	}

	return 0;
}