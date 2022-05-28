#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;


/*

-------------------------------------------------------------------------------------------------------------------------------------

Problem Statement:

	Given an array containing 0s,1s,and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can't
	counts 0s,1s and 2s to create the array.

-------------------------------------------------------------------------------------------------------------------------------------


This is another example for the 2 pointer algorithm, because the input array only consists of three
elements, so that we only need to keep track of 2 types of elements, so that once we swap 2 and zeros to
the end and start respectively. The 1 will automatically comes to center.

And the tricky part of this question, while coming up with the number 2, don't increase the i value.
Because if the swapped value is zero. There is a chance that the swapped zero won't get swapped to front
later, because the i has moved past that swapped zero. This is only the part which need to be taken care
of.

*/

void dutchFlag(vector<int> &inputVector){

	int start = 0;

	int end = inputVector.size() - 1;

	int i = 0;

	while( i <= end){

		if(inputVector[i] == 0){
			swap(inputVector[i], inputVector[start]);
			start += 1;
			i += 1;
		}

		else if(inputVector[i] == 1){
			i += 1;
		}

		else{
			swap(inputVector[i], inputVector[end]);
			end -= 1;
		}

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
	
		int size, inputElement;

		cin >> size;

		vector<int> inputVector;

		for(int i = 0; i < size; i++){
			cin >> inputElement;

			inputVector.pb(inputElement);

		}

		dutchFlag(inputVector);

		print(inputVector);

	}

	return 0;
}