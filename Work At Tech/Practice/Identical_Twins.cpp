#include<bits/stdc++.h>

using namespace std;

struct Node{

	int value = 0;
};

int factorial(int n){
	int factorial = 1;

	for(int i = 2; i <= n ; i++){
		factorial *= i;
	}

	return factorial;
}

int combination(Node n, int r){
	return factorial(n.value) / (factorial(r) * factorial(n.value - r));
}

int getIdenticalTwinsCount(vector<int> &arr) {

	map<int,Node> duplicateCount;

	for(int i = 0; i < arr.size() ; i++){
		duplicateCount[arr[i]].value += 1;
	}

	int pairCount = 0;

	for(auto i : duplicateCount){

		if(i.second.value >= 2){
			// cout<< pairCount << " " ;
			pairCount += combination(i.second , 2);
		}

	}

	return pairCount;



}

int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T; 

	cin >> T;

	while(T--){
		
		vector<int> input;
		
		int vectorElement;
		
		int inputSize;

		cin >> inputSize; 

		for(int i = 0 ; i < inputSize ; i++) {

			cin >> vectorElement;

			input.push_back(vectorElement);
		}

		cout << getIdenticalTwinsCount(input) << endl;
	
	}

	return 0;


}



	// add your logic here
