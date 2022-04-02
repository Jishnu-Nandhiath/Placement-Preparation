#include<bits/stdc++.h>

using namespace std;

void print(vector<int> printVector){

	for(int i = 0; i < printVector.size(); i++) {
		cout << printVector[i] << " ";
	}

	cout << "\n" ;

}

int digitCounter(int inputNumber){
	int digitCount = 1;



	inputNumber = inputNumber / 10;

	while(inputNumber != 0){

		inputNumber = inputNumber / 10;

		digitCount += 1; 
	}

	return digitCount;
}


vector<int> getEvenDigitNumbers(vector<int> arr) {
    // add your logic here

	vector<int> outputVector;

    for(int i = 0 ; i < arr.size() ; i++){
    		if(digitCounter(arr[i]) % 2 == 0){
    			outputVector.push_back(arr[i]);
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
			print(getEvenDigitNumbers(input));
	}

	return 0;

}