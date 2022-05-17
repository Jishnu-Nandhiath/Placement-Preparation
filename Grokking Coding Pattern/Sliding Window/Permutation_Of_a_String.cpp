#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << " , "; cout << endl;

using namespace std;

/*
This is a question of fixed sliding window pattern. 

Because in this question, we need to check whether the permutation of the given string is inside the input string, so that order
doesn't matter. We only need to check whether the no of characters in the input pattern is in the given input string window having
the size of pattern. 

So we use hashmap to keep track of character frequency in pattern map.

And decrement the hashmap key : values whenever we encounter a valid character inside input string, and keep track of the character
matches using another integer variable. Using hashmap only increases complexity and unwanted search iterations to find whether the
key value is zero, or whether exists and all sorts of things. 

So to make it simple, we can use another integer variable. And matched integer becomes zero, is when all the occurence of a specified
character is found in the input string. Then only we increment the matched count by 1. 

Since another matched variable is used, we don't necessarily need to erase a character key value from the map. We only need to check
whether it's zero or not. And when the character leaving window is part of the pattern string, we need to decrement the matched integer
value by 1.

And the program exits when the matched integer becomes equal to the map size, that is the number of unique characters in the pattern.


The if condition to check whether all characters is matched is kept in between adding matched by 1, and decrementing matched by 1.

if(windowEnd >= window)

This checks whether the window size became equal to the pattern length. 

on the first half of the for loop matched gets added by 1. 

So for a window of size 2. When on the index 2. on the first half window size is 2,
and on the second half of the for loop the window size becomes 1. And on the next iteration the first half window size becomes 2 again.

This is why the matched if check is kept in between the 2. So that the check happens exactly when the window size is 2. 

if(windowEnd > window)

if the above condition is used, the matched if check needs to be implemented on the bottom of the if loop.


*/



bool isPermutation(string inputString, string pattern){

	map<char,int> patternFrequencyMap;

	int window = pattern.size();

	for(int i = 0; i < window; i++){
		patternFrequencyMap[pattern[i]] += 1;
	}

	int windowStart = 0;

	int matched = 0;

	for(int windowEnd = 0; windowEnd < inputString.length(); windowEnd++){

		if(patternFrequencyMap.find(inputString[windowEnd]) != patternFrequencyMap.end()){

			patternFrequencyMap[inputString[windowEnd]] -= 1;

			if(patternFrequencyMap[inputString[windowEnd]] == 0){

				matched += 1;

			}
		}


		if(patternFrequencyMap.size() == matched)
			return true;

		if(windowEnd >= window - 1){
			
			if(patternFrequencyMap.find(inputString[windowStart]) != patternFrequencyMap.end()){
				
				if(patternFrequencyMap[inputString[windowStart]] == 0){
					matched -= 1;
				}
			
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