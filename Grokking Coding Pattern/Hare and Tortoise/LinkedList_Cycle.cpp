#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

struct Node{
	int data;
	Node* next;
};


// class Node{
// public:
// 	int data;
// 	Node *next;

// 	Node(){
// 		data = 0;
// 		next = NULL;
// 	}

// 	Node(int data){
// 		this -> data = data;
// 		this -> next = NULL;
// 	}
// };

bool linkedListCycle(Node *head){

	Node* slow = head;
	Node* fast = head;

	while(fast != NULL && fast -> next != NULL){

		slow = slow -> next;
		fast = fast -> next -> next;

		if(slow == fast)
			return true;

	}

	return false;

}


int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int element;

	int	i = 0;

	Node* head;

	Node* itr;

	Node* tail;

	while(cin >> element){

		Node* current = new Node;

		current -> data = element;
		current -> next = NULL;

		if(i == 0){
			head = current;
			itr = current;
		}
		else{
			itr -> next = current;
			itr = current;
		}
		i += 1;
	}

	tail = itr;

	tail -> next = head -> next -> next; // creating a cycle

	itr = head;

	//print iterator doesn't work for linked list with cycles

	// while(itr != NULL){
	// 	cout << itr -> data << " ";
	// 	itr = itr -> next;
	// }

	// cout << endl;

	string output = linkedListCycle(head) == 1 ? "Found the Cycle" : "No Cycle";

	cout << output << endl;

	return 0;
}