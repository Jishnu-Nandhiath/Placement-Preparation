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

Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates
in-place return the new length of the array.

-------------------------------------------------------------------------------------------------------------------------------

This is another simple example of the 2 pointer approach. 

There is 2 pointers in this problem, where one will sit at the currently found unique element,
and other will skip all other duplicate elements to arrive at the next unique element, only then
the if condition is executed. 

We only need to return the count of unique elements in this problem.

In here 'windowStart' will sit at the unique element, and 'windowEnd' will iterate to find the next
unique element. And when the next unique element comes up the 'windowStart' will get updated to the 
'windowEnd'. 

Since the array is sorted, all the duplicate elements will be adjacent.


*/



int uniqueSize(vector<int> duplicateArray){

	int windowStart = 0, uniqueCount = 1;

	if(duplicateArray.size() == 0 || duplicateArray.size() == 1){
		return duplicateArray.size();
	}

	for(int windowEnd = 1; windowEnd < duplicateArray.size(); windowEnd++){
		
		if(duplicateArray[windowStart] != duplicateArray[windowEnd]){
			windowStart = windowEnd;
			uniqueCount += 1;
		}
	}

	return uniqueCount;
}



int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;


	while(T--){
		
	int vectorSize;

	cin >> vectorSize;

	int vectorElement;

	vector<int> duplicateArray;

	for(int i = 0; i < vectorSize; i++){
		cin>>vectorElement;

		duplicateArray.pb(vectorElement);

		}

		cout << uniqueSize(duplicateArray) << endl;
	
	}

	return 0;
}