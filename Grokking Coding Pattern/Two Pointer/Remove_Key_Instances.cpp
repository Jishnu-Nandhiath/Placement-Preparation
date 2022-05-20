#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

Well, it's just ultra easy.

Yeah and you have just modified the input array in O(1) by passing the function parameter as
reference.

vector resizing is used to just remove the other unwanted elements after removal.

*/

int removeKeyInstancesLength(vector<int> &inputVector, int key){ 

	int arrayLength = 0;

	for(int i = 0; i < inputVector.size(); i++){
		if(inputVector[i] != key){
			
			inputVector[arrayLength] = inputVector[i];
			arrayLength+=1;
		
		}
	}

	inputVector.resize(arrayLength);

	return arrayLength;
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
		int k, vectorElement, vectorSize;

		cin >> vectorSize >> k;
	
		vector<int> inputVector;

		for(int i = 0; i < vectorSize; i++){
			cin >> vectorElement;

			inputVector.pb(vectorElement);
		}

		cout << removeKeyInstancesLength(inputVector,k) << endl;

		print(inputVector);
	}

	return 0;
}