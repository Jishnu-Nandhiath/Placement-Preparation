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
	
	Given the head of a singly linkedlist, write a method to return the middle node of the linkedlist.

	If the total number of nodes in the linkedlist, is even return the second middle node.

	eg : 1,2,3,4,5,6 ; Return 4.

-------------------------------------------------------------------------------------------------------------------------------------


*/

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

int linkedListMiddle(Node* head){

	Node* slow = head;
	Node* fast = head;

	while(fast && fast -> next){
		slow = slow -> next; 
		fast = fast -> next -> next;
	}

	return slow -> data;

}

int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int element;

	int i = 0;

	Node* head;
	Node* itr;

	while(cin >> element){

		Node* newNode = new Node(element);


		if(i == 0){
			head = newNode;
			itr = head;
		}else{
			itr -> next = newNode;
			itr = newNode;
		}

		i += 1;


	}

	cout << linkedListMiddle(head);

	return 0;
}