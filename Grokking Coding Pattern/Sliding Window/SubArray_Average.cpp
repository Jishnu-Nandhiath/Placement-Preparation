/*

-------------------------------------------------------------------------------------------------------------------------------

Problem Statement:

Find the average of contiguous subarrays of given size k, inside the input array.

-------------------------------------------------------------------------------------------------------------------------------

*/


#include<bits/stdc++.h>

using namespace std;

#define print(a) for(auto x : a ) cout << x << " "; cout << endl; 


/*
-------------------------------------------------------------------------------------------------------

In this problem, we need to keep track of the average associated with a given window size.
So, the if loop is enough in this case, because we're checking whether the array index of windowSize - 1
has been exceeded or not, after this point we need to add the next element, and remove the last element
one by one.

In case of fixed sliding window : if checker is enough
In case of dynamic sliding window : while loop is required.

--------------------------------------------------------------------------------------------------------
*/


vector<float> subArrayAverage(vector<int> inputVector, int k){

	vector<float> subArrayAverage1;

	float windowAverage = 0.0;
	int windowSum = 0, windowStart = 0;
	for(int i = 0; i < inputVector.size() ; i++){

		windowSum += inputVector[i];

		
		if(i >= k - 1){

			// the C++ way of type conversion in operations. (type) operation

			windowAverage = (float)windowSum / k;

			windowSum = windowSum - inputVector[windowStart];

			windowStart += 1;

			subArrayAverage1.push_back(windowAverage);
		}
	}

	return subArrayAverage1;
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	/* Input format:

	10 3 (input array size : subarray size - k)
	1 2 3 4 5 6 7 8 9 10 (input integer array)

	*/

	vector<int> inputVector;

	int inputElement, vectorSize, k;

	cin >> vectorSize >> k;

	for(int i = 0 ; i < vectorSize ; i++){
		
		cin >> inputElement;

		inputVector.push_back(inputElement);

	}

	print(subArrayAverage(inputVector,k));

}