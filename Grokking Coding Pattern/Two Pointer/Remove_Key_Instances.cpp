#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

int removeKeyInstancesLength(vector<int> inputVector, int key){ 

	int arrayLength = 0;

	for(int i = 0; i < inputVector.size(); i++){
		if(inputVector[i] != key){
			arrayLength+=1;
		}
	}
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
	}

	return 0;
}