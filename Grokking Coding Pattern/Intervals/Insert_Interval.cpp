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
	
	Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position
	and merge all necessary intervals to produce a list that has only mutually exclusive intervals.

----------------------------------------------------------------------------------------------------------------------

In here the Naive approach will be adding the interval, sorting and merging them, The time complexity will be O(N*logN)

Since the vector is already sorted, we don't need to sort it again.

We only need to find a position where the interval has to be added. So, the approach will be finding the right position.

First we need to skip all elements until an interval end is greater than the start of inserting interval.

And we're finding the end, by finding the position where start of an interval is greater than the end of the inserting interval.

And start will be min(start, and the current start)
end = max(end, currentEnd)

And then adding remaining elements.

Even if 3 while loops are there, time complexity is O(N).

Because i value is incremented at each loop, and not modified back to zero.
*/


vector<pair<int,int>> solve(vector<pair<int,int>> inputIntervalVector, pair<int,int> insertInterval){
	
	int i = 0;

	vector<pair<int,int>> resultInterval;

	int start = insertInterval.first;
	int end = insertInterval.second;


	//skipping all intervals until the insert interval position is found.
	while(i < inputIntervalVector.size() && inputIntervalVector[i].second <= insertInterval.first){
		resultInterval.pb(inputIntervalVector[i]);
		i += 1;
	}

	// Trying to find the insert interval position, and to merge all the intervals in between.
	while(i < inputIntervalVector.size() && inputIntervalVector[i].first <= insertInterval.second){
		start = min(start, inputIntervalVector[i].first);
		end = max(end, inputIntervalVector[i].second);
		i += 1;
	}

	resultInterval.pb({start,end});

	// Adding the remaining intervals if any, after adding the interval.
	while(i < inputIntervalVector.size()){
		resultInterval.pb(inputIntervalVector[i]);
	}

	return resultInterval;

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

			pair<int,int> interval(first,second);

			inputIntervalVector.pb(interval);
		
		}

		cin >> first >> second;

		pair<int,int> insertInterval(first,second);

		printPair(solve(inputIntervalVector, insertInterval));

	}

	return 0;
}