#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/* 

---------------------------------------------------------------------------------------------------------------------

Problem Statement:

Given an array of characters where each character represents a fruit tree, you are given two baskets
and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket
can have only one type of fruit.


---------------------------------------------------------------------------------------------------------------------

This is exactly same as longest substring with k distinct letters, except the fact that k in this problem is 2.
Nothing else is changed.

*/

int maximumFruits(vector<char> fruitTree){
	int windowStart = 0, largestFruitNumber = 0;

	map<char,int> fruitBaskets;

	for(int i = 0; i < fruitTree.size(); i++){
			fruitBaskets[fruitTree[i]] += 1;


		while(fruitBaskets.size() > 2){

			fruitBaskets[fruitTree[windowStart]] -= 1;

			if(fruitBaskets[fruitTree[windowStart]] == 0)
				fruitBaskets.erase(fruitTree[windowStart]);

			windowStart += 1;

		}

		largestFruitNumber = max(largestFruitNumber, i - windowStart + 1);
	}

	return largestFruitNumber;
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	int flag = 1; // ignore first new line after taking T input

	cin >> T;

	char fruits;

	while(T--){

		if(flag == 1)
			cin.ignore();

		flag = 0;

		string fruitTrees;

		vector<char> fruitTreeList;

		getline(cin, fruitTrees);


		stringstream inputStream(fruitTrees);

		while(inputStream >> fruits){
			fruitTreeList.pb(fruits);
		}

		// print(fruitTreeList);

		cout << maximumFruits(fruitTreeList) << endl;
	}

	return 0;
}