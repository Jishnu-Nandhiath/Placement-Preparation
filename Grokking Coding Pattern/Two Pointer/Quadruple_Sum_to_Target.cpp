#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}

using namespace std;


/*

This is a brute force solution, I don't know whether better solutions exists for this kind of problems. 

Howerver using the 2 pointer approach we can only eliminate the use of one for loop, so that for finding 4 numbers we can
do that in O(N*3) in the worst case. 

And one of the simple tricky thing that we've done here is like, since the for loop iterating with i is to find the first
element, it is only going to iterate upto the point to the last 3 elements, becasue they will be taken care by other loops.

And the jth loop is to find the second element. So, that it only need to iterate upto last 2 elements, because it will be taken
care by the 2 pointer loop that we've implemented below that given loop.


*/




vector<vector<int>> quadrauplets(int target, vector<int> inputVector){


	vector<vector<int>> outputVector;

	sort(inputVector.begin(), inputVector.end());

	for(int i = 0 ; i < inputVector.size() - 3; i++){

		if(i > 0 && inputVector[i] == inputVector[i - 1]){
			continue;
		}

		for(int j = i + 1; j < inputVector.size() - 2; j++){

			if(inputVector[j] == inputVector[j - 1])
				continue;

			int right = inputVector.size() - 1;
			int left  = j + 1;

			while(left < right){

				int netSum = inputVector[i] + inputVector[j] + inputVector[left] + inputVector[right];

				if(netSum == target){

					outputVector.pb({inputVector[i],inputVector[j],inputVector[left],inputVector[right]});

					right -= 1;
					left += 1;


				while(inputVector[left] == inputVector[left + 1])
					left += 1;

				while(inputVector[right] == inputVector[right - 1])
					right -= 1;

			}

			else if(netSum > target){

				right -= 1;

			}else{
				left += 1;
			}

			}

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
	
		int size, target, inputElement;

		vector<int> inputVector;

		cin >> size >> target;

		for(int i = 0; i < size; i++){
			cin >> inputElement;

			inputVector.pb(inputElement);
		}

		print2(quadrauplets(target,inputVector));

	}

	return 0;
}