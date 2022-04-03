//bruteforce approach, Causes TLE on submission

//A good reference for a quick solution

// Time Complexity : O(n^2)


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

    vector<int> subArray1(arr.begin(),arr.begin()+endIndex + 1);
    vector<int> subArray2(arr.begin() + endIndex + 1, arr.end());

    sort(subArray1.begin(),subArray1.end());
    sort(subArray2.begin(),subArray2.end());

    int n1 = subArray1.size(), n2 = subArray2.size();

    int subArray1Large = subArray1[n1 - 1];

    subArray1.resize(n1 + n2);

    int j = 0;

    int temp = 0;

    	for(int i = temp ; i < n1+n2 ; i++){
    		if(subArray1[i] >= subArray2[j]){
    			temp = i;
    			for(int start = n1+n2 - 2; start >= i ; start--){
    				subArray1[start+1] = subArray1[start];
    			}
    			subArray1[i] = subArray2[j];
    			j++;
    		}
    	if(subArray2[j] > subArray1Large || j == n2){
    	    break;
    	}

		} 


    while(j < n2){
    	subArray1[n1 + n2 - j] = subArray2[j];
    	j++;
    }

    arr = subArray1;

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