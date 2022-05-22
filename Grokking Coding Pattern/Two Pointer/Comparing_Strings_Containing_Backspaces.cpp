#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

bool checkString(string str1, string str2){

	string out1 = "", out2 = "";

	int hashCount = 0;

	int i = str1.length() - 1;

	while(i >= 0){

		if(str1[i] == '#'){
			hashCount += 1;

			i -= 1;

		}else{

			if(hashCount == 0){

				out1 += str1[i];
				i-= 1;

			}else{

				i = i - hashCount;

			}

			hashCount = 0;
		}

	}

	hashCount = 0;

	int j = str2.length() - 1;

	while(j >= 0){

		if(str2[j] == '#'){
			hashCount += 1;

			j -= 1;

		}else{

			if(hashCount == 0){

				out2 += str2[j];
				j -= 1;

			}else{

				j = j - hashCount;

			}

			hashCount = 0;
		}

	}


	// cout << out1 << out2;

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