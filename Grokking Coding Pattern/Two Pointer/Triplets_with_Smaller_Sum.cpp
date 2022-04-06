#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

int smallerSumTriplets(vector<int> inputVector, int target){
	int count = 0;

	sort(inputVector.begin(),inputVector.end());

	for(int i = 0; i < inputVector.size(); i++){
		int left = i + 1, right = inputVector.size() - 1;

		while(left < right){
			int targetSum = inputVector[left] + inputVector[right] + inputVector[i];

			if(targetSum < target){

				count += right - left;
				left += 1;

			/* below while snippet can be used if the vector contains duplicates.*/
			// while(left < right && inputVector[left] == inputVector[left - 1])
			// 	left += 1;
			// while(left < right && inputVector[right] == inputVector[right + 1])
			// 	right -= 1;
			}else{
				right -= 1;
			}

		}
	}

	return count;
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){

		int target, vectorElement, vectorSize;

		cin >> vectorSize >> target;

		vector<int> inputVector;

		for(int i = 0; i < vectorSize; i++){
			cin >> vectorElement;
			inputVector.pb(vectorElement);
		}

		cout << smallerSumTriplets(inputVector,target) << endl;
	
	}

	return 0;
}