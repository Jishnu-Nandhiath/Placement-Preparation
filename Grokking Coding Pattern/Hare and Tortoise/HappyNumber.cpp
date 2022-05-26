#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

/*

Since we're checking whether a cycle exists, we can use the hare and tortoise approach.


*/



int digitSquareSum(int num){

	int sum = 0;

	int lastDigit;

	while(num){

		lastDigit = num % 10;

		sum += pow(lastDigit,2);

		num = num / 10;

	}

	return sum;

}


bool checkHappyNumber(int num){


	int slow = num; 
	int fast = num; 
	int temp;

	while(true){


		slow = digitSquareSum(slow);

		temp = digitSquareSum(fast);

		fast = digitSquareSum(temp);


		if(slow == 1 || fast == 1){
			return true;
		}

		if(slow == fast){
			break;	
		}

	}

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

		int num;

		cin >> num;

		cout << checkHappyNumber(num);

	}

	return 0;
}