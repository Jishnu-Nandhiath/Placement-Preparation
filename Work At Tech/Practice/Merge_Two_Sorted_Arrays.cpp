#include<bits/stdc++.h>

using namespace std;

void print(vector<int> printVector){

	for(int i = 0; i < printVector.size(); i++) {
		cout << printVector[i] << " ";
	}

	cout << "\n" ;

}


vector<int> mergeSortedArrays(vector<int> A, vector<int> B) {

  int i = 0, j = 0, k = 0;

  int n1 = A.size(), n2 = B.size();



  vector<int> outputVector(n1+n2);

  while (i < n1 && j < n2) {

    if (A[i] < B[j])
      outputVector[k++] = A[i++];
    else
      outputVector[k++] = B[j++];
  }

  while (i < n1)
    outputVector[k++] = A[i++];

  while (j < n2)
    outputVector[k++] = B[j++];

	return outputVector;
}





int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// cout<<"hi";

	int T; 

	cin >> T;


	while(T--){

		vector<int> inputA, inputB;
		
		int vectorElement;
		
		int m,n;

		cin >> m >> n; 

		for(int i = 0 ; i < m ; i++) {

			cin >> vectorElement;

			inputA.push_back(vectorElement);
		}

		int anotherElement;

		for(int j = 0 ; j < n ; j++) {

			cin >> anotherElement;

			inputB.push_back(anotherElement);
		}

	    vector<int> output = mergeSortedArrays(inputA,inputB);
	
	    print(output);
	    
	}

	return 0;

}