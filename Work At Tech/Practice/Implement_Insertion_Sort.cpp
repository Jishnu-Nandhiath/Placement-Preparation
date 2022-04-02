#include<bits/stdc++.h>

using namespace std;

void print(vector<int> printVector){

	for(int i = 0; i < printVector.size(); i++) {
		cout << printVector[i] << " ";
	}

	cout << "\n" ;

}

void insertionSort(vector<int> &arr) {
    // add your logic here
	for(int i = 1 ; i < arr.size() ; i++){
		int key = arr[i];
		
		int j = i - 1;
		
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
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
			insertionSort(input);

			print(input);
	}

	return 0;

}