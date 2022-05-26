#include<bits/stdc++.h>


#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

// struct Node{
// 	int data;
// 	Node* next;
// };

/*

--------------------------------------------------------------------------------------------------------------------

Problem Statement: 

Given the head of a singly linkedlist, write a function to determine if the linkedlist has a cycle in it or not.

--------------------------------------------------------------------------------------------------------------------


Two pointers, one moving twice as fast the other, if they meet there is a cycle in the linkedlist.

Some interesting qustions I asked in here is:

1. Why dynamic allocation is used for linked list ?

	Because while creating a node, we are not sure how many more nodes get attatched to that node. Hence dynamic
	allocation. And in dynamic allocation the new keyword will allocate memory to the pointer. Hence the pointer
	is already about memory management. 

	A new node needs to be memory allocated before usage. Because usage of the node is based on the memory it is 
	allocated on itself. So, static allocation doesn't work. Read more on this.

2. Who Aaaarrree you ?
	
	Well it is what it is. And this is what this is. Don't who, who is. Well everyone is fine.

	Life is this. This is life. 

	This is called a programmer's breakdown at unknown time in unknown timezone. Possibly 4AM I guess.

	Well who cares, let's keep coding.


*/

class Node{
public:
	int data;
	Node *next;

	Node(){
		data = 0;
		next = NULL;
	}

	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}
};



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

		Node* current = new Node(element);

		// current -> data = element;
		// current -> next = NULL;

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

	// tail -> next = head -> next -> next; // creating a cycle

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