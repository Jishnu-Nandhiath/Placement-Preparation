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

Given a string, find the length of the longest substring which has no repeating characters.



-------------------------------------------------------------------------------------------------------------------------------

The if loop condition is checking whether the char at current index is already present in the map.

If it is already present in the map, then we can update the windowStart by checking the last time the
character has been added in the map so that the index + 1 will be our windowStart.

There might be chances that the windowStart has been already moved past the last index of the current
duplicate character, that's why we're taking the max of windowStart and the charIndex + 1.

Like abcdba.

Sample: In the above string when the iterator reaches the second b. The windowStart will move to the index
of c to avoid all other duplicates inside the window.

And when the iterator reaches 'a' after the second 'b'. The a is also present in the map, we saved it in the 0th 
index. But the windowStart has already moved to 2nd index. So that's why we're taking the max of windowStart
instead of assigning it directly to the current char's previous index + 1.

After that we're also updating or replacing the current index of the char by the new index. 


*/



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