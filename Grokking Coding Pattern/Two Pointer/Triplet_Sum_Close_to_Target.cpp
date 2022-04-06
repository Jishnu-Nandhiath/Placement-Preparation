#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;


int targetSumTriplet(vector<int> inputVector, int k){

	sort(inputVector.begin(),inputVector.end());

	int closestTarget = INT_MAX;

	vector<int> outputVector;


	for(int i = 0; i < inputVector.size(); i++){
		int left =  i + 1, right = inputVector.size() - 1;

		while(left < right){
			int targetDiff = k - inputVector[left] - inputVector[right] - inputVector[i];

			if(targetDiff == 0)
				return k - targetDiff;


			/* second part of the if loop is to ensure that the output will be always
			the left of the target sum. such that problem statement says that if
			2 closest triplet exists, return the triplet with smallest sum.
			The smallest sum triplet will always reside in the left side of target sum,
			in the number line.
			*/

			if(abs(targetDiff) < abs(closestTarget) || (abs(targetDiff) == abs(closestTarget) && targetDiff > closestTarget))
				closestTarget = targetDiff;
		
			if(targetDiff > 0)
				left += 1;
			else
				right -= 1;
		}
	}

	return k - closestTarget;

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

		cout << targetSumTriplet(inputVector, k) << endl;

	}

	return 0;
}