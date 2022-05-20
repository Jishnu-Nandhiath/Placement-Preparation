#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;


vector<vector<int>> tripletSumZero(vector<int> inputVector){



}



int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		int size;

		cin >> size;

		int inputElement;

		vector<int> inputVector;

		for(int i = 0; i < size; i++){

			cin >> inputElement;

			inputVector.pb(inputElement);
		}

		print(tripletSumZero(inputVector));

	}

	return 0;
}