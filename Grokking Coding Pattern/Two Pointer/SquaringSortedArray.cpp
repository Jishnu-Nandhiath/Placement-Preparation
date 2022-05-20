#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

vector<int> squareSortedArray(vector<int> inputVector){

	int start = 0;
	int end = inputVector.size() - 1;

	vector<int> outputVector;

	// outputVector.resize(inputVector.size());

	while(start <= end){
		if(abs(inputVector[start]) > abs(inputVector[end])){
			outputVector.pb(pow(inputVector[start], 2));
			start += 1;
		}else{
			outputVector.pb(pow(inputVector[end], 2));
			end -= 1;
		}
	}

	return outputVector;

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

		while(size--){
			cin >> inputElement;
			inputVector.pb(inputElement);
		}

		print(squareSortedArray(inputVector));

	}

	return 0;
}