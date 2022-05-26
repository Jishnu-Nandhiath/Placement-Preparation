#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;


/*

This is a simple implementation based on my logic, where the iteration begins fromt the end of the string,
so that whenever a backspace comes up, the consecutive elements can be skipped. And add the characters which
remains. 

And in the end, compare the both.

Another efficient approach would be using another loop continuously call this function index by index, so that
we can break whenever a mismatch has occured. This solution is in grokking the coding pattern.

The approach would be more time complex than this one, in the worst case. 

Here we're using some extra space to store the output.

*/


string resultString(int stringLength, string str){

	int hashCount = 0;

	while(stringLength >= 0){

		if(str[stringLength] == '#'){

			hashCount += 1;

			stringLength -= 1;

		}else{

			if(hashCount == 0){

				out += str[stringLength];
				stringLength -= 1;

			}else{

				stringLength -= hashCount;

			}

			hashCount = 0;
		}

	}

	return out;

}



bool checkString(string str1, string str2){

	string out1 = "", out2 = "";

	int hashCount = 0;

	int i = str1.length() - 1;

	out1 = resultString(str1.length() - 1, str1);

	out2 = resultString(str2.length() - 1, str2);

	if( out1 == out2)
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

		string str1, str2;

		cin >> str1 >> str2;
	
		cout << checkString(str1, str2);

	}

	return 0;
}