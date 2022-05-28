#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define printPair(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define printNested(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

/*

--------------------------------------------------------------------------------------------------------------------------

Problem Statement:

	Given a set of intervals, find out if any two intervals overlap.


--------------------------------------------------------------------------------------------------------------------------

This question is exactly similar to merge intervals. Except the fact that we're breaking the loop whenever a inclusive
interval is found.

*/

bool sortCol(pair<int,int> &first, pair<int,int> &second){
	return first.first <= second.first;
}

bool solve(vector<pair<int,int>> inputIntervalVector){
	
	sort(inputIntervalVector.begin(), inputIntervalVector.end(),sortCol);

	int start = inputIntervalVector[0].first;
	int end = inputIntervalVector[0].second;

	for(int i = 1; i < inputIntervalVector.size(); i++){

		pair<int,int> interval = inputIntervalVector[i];

		if(interval.first <= end){
			return true;
		}

		start = interval.first;
		end = interval.second;

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
	
		int size, first, second;

		cin >> size;

		vector<pair<int,int>> inputIntervalVector;

		for(int i = 0; i < size; i++){

			cin >> first >> second;

			pair<int,int> interval(first, second);

			inputIntervalVector.pb(interval);
		
		}

		cout << solve(inputIntervalVector);

	}

	return 0;
}