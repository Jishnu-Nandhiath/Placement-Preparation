#include<bits/stdc++.h>

using namespace std;

void print(vector<int> printVector){

	for(int i = 0; i < printVector.size(); i++) {
		cout << printVector[i] << " ";
	}

	cout << "\n" ;

}

vector<int> getCumulativeSum(vector<int> &arr) {

	int cumulativeSum = 0;


	for(int i = 0 ; i < arr.size(); i++){
		
		cumulativeSum += arr[i];
		
		arr[i] = cumulativeSum; 

		}

	return arr;

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

		
	
		
		
		

		print(getCumulativeSum(input));
	}

	return 0;


}



	// add your logic here
