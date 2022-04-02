#include<bits/stdc++.h>

using namespace std;

void print(vector<int> printVector){

	for(int i = 0; i < printVector.size(); i++) {
		cout << printVector[i] << " ";
	}

	cout << "\n" ;

}

vector<int> getPositiveCumulativeSum(vector<int> &arr) {

	int positiveCumulativeSum = 0;

	vector<int> outputVector;

	for(int i = 0 ; i < arr.size(); i++){
		
		positiveCumulativeSum += arr[i];

		if(positiveCumulativeSum > 0 ){

			outputVector.push_back(positiveCumulativeSum);
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
		
		vector<int> input;
		
		int vectorElement;
		
		int inputSize;

		cin >> inputSize; 

		for(int i = 0 ; i < inputSize ; i++) {

			cin >> vectorElement;

			input.push_back(vectorElement);
		}
		

		print(getPositiveCumulativeSum(input));
	}

	return 0;


}



	// add your logic here
