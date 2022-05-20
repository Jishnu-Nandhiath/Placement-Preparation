#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/* This is a question of the type fixed sliding window.

Where the window size is the total words length in the input array.

Because since the words are concatenated we need to find them adjacently. And they can also be concatenated in 
any order. So that we need to keep the count of words, so that we can cross check whether they are found or not.

In this question first we will create a frequency map to keep track of all the count of words found in the input
array which gets concatenated to produce the result.

And the first for i loop is to iterate until the last starting index of the inputString. 

for example if the input string is catfoxcat. and the input array is [cat, fox]

Then the last possible starting index is 4. after 4 to the end, there is 9 characters. So that they can be iterated
from that point onwards. 

the 2nd j loop is to iterate by each word, so that for the above case,

when i = 0, words will be 0 : 3, 3 : 6, 
when i = 1, words will be 1 : 4, 4 : 7

j loop is specifically to find whether the word is valid, ie, the word is already in the frequencyMap, or whether
the word count is exceeded that in the frequency map.

If any of the above mentioned conditions fails, the j loop will break, So that only a valid case will make it to the
end of the j for loop. So that at the end, we can add the starting index as i.


The time complexity is O(M * N * len)

The question is a bit complex, solving in linear time will be highly challenging.

*/

vector<int> wordConcatFinder(string inputString, vector<string> words){


	if(inputString.length() == 0 || words[0].length() == 0)
		return {};

	map<string,int> wordFrequencyMap;
	vector<int> wordIndices;

	int wordCount = words.size();
	int wordLength = words[0].length();


	for(int i = 0; i < words.size(); i++){
		wordFrequencyMap[words[i]] += 1;
	}


	int lastStartingIndex = (inputString.length() - wordCount * wordLength ) + 1;

	//we're iterating the first loop until the last possible starting index of the words.

	int nextWordIndex;

	for(int i = 0; i < lastStartingIndex; i++){
		
		map<string,int> wordsSeen;
		
		for(int j = 0; j < wordCount; j++){
			nextWordIndex = i + j * wordLength;

/* 
This is to get the starting index of all the possible word concatenations. And since the words are concatenated
the words will be adjacent, so inside the 2nd for loop we're only iterating upto the second word. 

for word length = 3. 

i = 0. words will be 0 : 3, 3 : 6			
			
*/
		string word = inputString.substr(nextWordIndex,wordLength);

		if(wordFrequencyMap.find(word) == wordFrequencyMap.end()){
			break;
		}

		if(wordsSeen.find(word) == wordsSeen.end()){
			wordsSeen[word] += 1;
		}

		if(wordsSeen[word] > wordFrequencyMap[word]){
			break;
		}

		if(j + 1 == wordCount){
			wordIndices.pb(i);
		}

		}
	}

	return wordIndices;

}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
		
		string inputString, vectorString;
		vector<string> inputVector;

		cin >> inputString;

		cin.ignore();

		getline(cin,vectorString);

		stringstream ss(vectorString);

		string word;

		while(ss >> word){
			inputVector.pb(word);
		}
	
		print(wordConcatFinder(inputString,inputVector));

	}

	return 0;
}