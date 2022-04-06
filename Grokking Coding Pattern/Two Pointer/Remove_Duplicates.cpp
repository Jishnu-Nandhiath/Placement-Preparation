#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

int uniqueSize(vector<int> duplicateArray){

	int windowStart = 0, uniqueCount = 1;

	if(duplicateArray.size() == 0 || duplicateArray.size() == 1){
		return duplicateArray.size();
	}

	for(int windowEnd = 1; windowEnd < duplicateArray.size(); windowEnd++){
		
		if(duplicateArray[windowStart] != duplicateArray[windowEnd]){
			windowStart = windowEnd;
			uniqueCount += 1;
		}
	}

	return uniqueCount;
}



int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int T;

	cin >> T;


	while(T--){
		
	int vectorSize;

	cin >> vectorSize;

	int vectorElement;

	vector<int> duplicateArray;

	for(int i = 0; i < vectorSize; i++){
		cin>>vectorElement;

		duplicateArray.pb(vectorElement);

		}

		cout << uniqueSize(duplicateArray) << endl;
	
	}

	return 0;
}