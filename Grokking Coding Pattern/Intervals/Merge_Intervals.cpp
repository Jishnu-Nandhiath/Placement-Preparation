#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define printPair(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define printNested(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

/*

----------------------------------------------------------------------------------------------------------------------

Problem Statement:

	Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive
	intervals.

----------------------------------------------------------------------------------------------------------------------

In this problem, we're using pair type to address the interval type inputs.

. First we've sorted the nested vector based on the first element of all those intervals.
	. Since the sort function has a third argument which is the function name based on which the element needs to be
	  Compared.

. So, since the start of all the intervals has been sorted out, we only need to compare the end of the vector.
  The if condition will be like comparing the end of the previous interval with the start of the next interval. So, that
  if they somehow overlap we can modify the current end accordingly.

 . And we're only adding the output to another vector when we meet a mutually exclusive element.

 . This is why the last interval is getting added outside the loop. Because it won't be taken care by the loop. As already
   explained for the current iteration, the interval in the previous iteration is getting added to the loop. 

 . So that, the interval gets added only if the inclusive interval condition breaks.

*/


bool sortCol(pair<int,int> &first, pair<int,int> &second){
	return first.first < second.first;
}

vector<pair<int,int>> solve(vector<pair<int,int>> inputIntervalVector){

	sort(inputIntervalVector.begin(), inputIntervalVector.end(), sortCol);
	
	vector<pair<int,int>> mergedIntervals;

	int start = inputIntervalVector[0].first;
	int end = inputIntervalVector[0].second;

	for(int i = 1; i < inputIntervalVector.size(); i++){

		pair<int,int> interval = inputIntervalVector[i];

		if(interval.first <= end){
			end = max(end,interval.second);
		}else{

			pair<int,int> exclusiveInterval(start,end);
			mergedIntervals.pb(exclusiveInterval);
			start = interval.first;
			end = interval.second;

		}
	}

	mergedIntervals.pb({start,end});

	return mergedIntervals;
}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		int size, first, second;

		cin >> size;

		vector<pair<int,int>> inputIntervalVector;

		for(int i = 0; i < size; i++){

			cin >> first >> second;

			pair<int,int> inputPair(first,second);

			inputIntervalVector.pb(inputPair);
		
		}

		printPair(solve(inputIntervalVector));

	}

	return 0;
}