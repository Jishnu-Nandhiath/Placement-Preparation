#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

If you're a beginner the basic intution will be to replace the characters in the array with same 
characters nearby and take the count. But that will be taking extra time and space 
complexity.

The key point in the problem is don't replace or manipulate the array unless and until you need to
print the array in that way. In this problem we only need to print the longest subarray length after
replacement, so there will be always some other way other than manipulating the input array to try and
replacing the values. Only need do it when you're forced to do it, means you're asked to print it after 
replacement in the output console. Else always think of something else.

==============================================================================================================

In here the algorithm is a bit tricky.

We're trying to keep track of the maximum number of same letter character inside a window and keeping
it in an integer variable.

That value only changes when we come across another character having more than same occurences than the
current character inside a window.

Max counting character is to check for the number of other characters apart from the current most repeating
char in the same window.

So that we can pop out the characters left of the window, by comparing thw window size after subtracting
the most repeating occurences with the k value. 


In here we're only checking whether the current repeating char value count is greater than the last one.
Else we don't care. Even if we passed that window we're still checking whether the current char has a count
greater than the last one.

This is because in a case like "

"aaabcdaaa"     k = 2
 
The if loop is triggered only when we reaches the letter d, then first a is removed, then again we reaches
the next stream of 'a' characters. Since bcd is inside the current window, we will be decreasing the 'a' count
and popping out the 'a' characters. So that we will only have the maximum possilble 'a' inside a window, instead
of the whole count 'a's in the array.

The implementation may seems a bit tricky. But it's efficient. Try yourself with some random inputs
to better understand the solution.

The if loop is like, when the window size exceeds more than k different characters other than the most repeating one, we enters
inside the if loop, and the window size remains the same after that. Because since we need the longest string after k replacements
we are only intersted when a larger window comes up. So, that we don't necessarily need to change the window size, because if the
output is going to change, the windowsize has to increase. 

So this problem can be categorized like Dynamic - Fixed Sliding Window (I named it myself  :) ")

*/


int longestSubstringWithSameLetters(string inputString, int k){

	int windowStart = 0, largestStringLength = 0, maxCountRepatingChars = 0;

	char rightChar, leftChar;

	map<char,int> frequencyMap;


	for(int i = 0; i < inputString.size(); i++){

		rightChar = inputString[i];

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

		cout << inputString << " : " << longestSubstringWithSameLetters(inputString, k) << endl;
	}

	return 0;
}