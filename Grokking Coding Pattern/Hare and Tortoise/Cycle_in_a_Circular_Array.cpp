#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

/*

------------------------------------------------------------------------------------------------------------------------

Problem Statement:

We are given an array containing positive and negative numbers, suppose the array contains a number 'M' at a particlular
index. Now, if 'M' is positive we will move forward 'M' indices and if 'M' is negative move backwards 'M' indices. You
should assume that the array is circular which means two things.

1. If while moving forward, we reach the end of the array, we will jump to the first element to continue the movement.

2. If while moving backward, we reach the beginning of the array, we will jump to the last element to continue the movement.

Write a method to determine if the array has a cycle. The cycle should have more than one element and should follow one direction
which means the cycle should not contain both forward and backward movements.

Note : this is why we need to preserve the direction of movement.

------------------------------------------------------------------------------------------------------------------------

In problems where, finding a cycle kind of question, which is not involving linkedlist, using a function is better,
to change the slow and fast pointer values.

Here we're basically checking the direction of movement continuously, and checking whether the pointers are equal.


*/


int nextIndex(vector<int> inputVector, bool isForward, int currentIndex){

	bool direction = inputVector[currentIndex] >= 0;


	// Used to check whether the direction has been changed or not. And returning -1 will break the loop, since it is a
	// non loop scenario, or it doesn't match the requirements for the loop in the problem.

	if(isForward != direction){
		return -1;
	}


	// Moving the index, modulo is good to check whether the pointers has passed the limits of the array.

	int next_index = (currentIndex + inputVector[currentIndex]) % inputVector.size();


	//This is to avoid, a single element cycle.
	if(next_index == currentIndex){
		return -1;
	}

	return next_index;
}


bool solve(vector<int> inputVector){
	
	int slow, fast;

	bool directionForward;

	//For loop is required since, the cycle may not need to start from the beginning of the array.

	for(int i = 0; i < inputVector.size(); i++){

		bool directionForward = inputVector[i] >= 0;	

		slow = i; fast = i;


		while(true){
			slow = nextIndex(inputVector, directionForward, slow);

			fast = nextIndex(inputVector, directionForward, fast);

			if(fast != -1){
				fast = nextIndex(inputVector, directionForward, fast);
			}

			// For any non loop scenario -1 is returned hence breaking the loop.
			if(slow == -1 || fast == -1 || slow == fast)
				break;

		}

	}

	if(slow != -1 && slow == fast)
		return true;

	return false;

}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;

	while(T--){
	
		int size, element;

		cin >> size;

		vector<int> inputVector;

		for(int i = 0; i < size; i++){

			cin >> element;

			inputVector.pb(element);
		
		}

		cout<<solve(inputVector) << endl;

	}

	return 0;
}