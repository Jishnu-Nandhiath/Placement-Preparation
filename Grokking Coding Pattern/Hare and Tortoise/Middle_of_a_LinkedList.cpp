#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;
#define print2(a) for(auto x : a){ for(auto y : x) cout << y << " ";cout << endl;}cout << endl;

using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(){
		data = 0;
		next = NULL;
	}

	Node(int val){
		data = val;
		next = NULL;
	}
};

int linkedListLength(Node* head){

	int len = 0;

	while(head){
		len += 1;
		head = head -> next;
	}
	return len;

}


int linkedListMiddle(Node* head){
	
}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	return 0;
}