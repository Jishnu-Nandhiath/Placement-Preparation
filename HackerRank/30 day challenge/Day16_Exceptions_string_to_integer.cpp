#include<bits/stdc++.h>

using namespace std;


int main(){
    string S;
    cin >> S;
    
try{
	cout<<stoi(S);
}
catch(exception &err){
	cout<<"Bad String";
}
    return 0;
}
