#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a){ for(auto y :x ) cout << y << " "; cout << endl;} 
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

vector<vector<int>> uniqueTripletCount(vector<int> inputVector){

	map<int,int> frequencyMap;

	vector<vector<int>> triplets;

	sort(inputVector.begin(),inputVector.end());

	int left = 0 ;

	for(int i = 0; i < inputVector.size(); i++){
		int right = inputVector.size() - 1, left = i+1;
		if(inputVector[i] == inputVector[i - 1] && i > 0)
			continue;

		int targetSum = - inputVector[i];

		while(left < right){
			
			int currentSum = inputVector[left] + inputVector[right];

			if(currentSum == targetSum){
				triplets.pb({inputVector[left],inputVector[right],-targetSum});
				left += 1;
				right -= 1;
			
			while(left < right && inputVector[left] == inputVector[left - 1])
				left += 1;
			while(left < right && inputVector[right] == inputVector[right + 1]){
				right -= 1;
				}
			}
			else if(currentSum > targetSum){
				right -= 1;
			}
			else if(currentSum < targetSum){
				left += 1;
			}
		}
	}
	return triplets;	
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;



	while(T--){
		
	int vectorSize, vectorElement;

	vector<int> inputVector;

	cin >> vectorSize;

	for(int i = 0; i < vectorSize; i++){
		cin >> vectorElement;

		inputVector.pb(vectorElement);
	}

	print(uniqueTripletCount(inputVector));


	}

	return 0;
}