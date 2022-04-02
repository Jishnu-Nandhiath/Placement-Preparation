#include<bits/stdc++.h>

using namespace std;

void print(vector<int> printVector){

	for(int i = 0; i < printVector.size(); i++) {
		cout << printVector[i] << " ";
	}

	cout << "\n" ;

}

void merge(vector<int> &arr, int endIndex) {
    // add your logic here

    vector<int> subArray1(arr.begin(),arr.begin()+endIndex);
    vector<int> subArray2(arr.begin() + endIndex, arr.end());

    sort(subArray1.begin(),subArray1.end());
    sort(subArray2.begin(),subArray2.end());

    int n1 = subArray1.size(), n2 = subArray2.size();

    subArray1.resize(n1 + n2);

    int j = 0;

    int temp = 0;

    while(j < n2){
    	for(int i = temp ; i < n1+n2 - 1 ; i++){
    		if(subArray1[i] >= subArray2[j]){
    			temp = i;
    			for(int start = n1+n2 - 1; start >= i ; start--){
    				subArray1[start+1] = subArray1[start];
    			}
    			subArray1[i] = subArray2[j];
    			j++;
    		}
    	}
    }
    
    arr.resize(n1 + n2);

    arr = subArray1 ;


    while(j < n2){
    	subArray1.push_back(subArray2[j]);
    	j++;
    }

}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T; 

	cin >> T;

	while(T--){

		vector<int> input;
		
		int vectorElement;
		
		int inputSize, endIndex;

		cin >> inputSize >> endIndex; 

		for(int i = 0 ; i < inputSize ; i++) {

			cin >> vectorElement;

			input.push_back(vectorElement);
		}

		merge(input,endIndex);

		print(input);
	
	}

	return 0;

}