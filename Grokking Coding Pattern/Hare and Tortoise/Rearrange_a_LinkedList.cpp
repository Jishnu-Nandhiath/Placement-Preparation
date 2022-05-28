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
	
	Given the head of a singly linkedlist, write a method to modify the linkedlist such that the nodes from the second half of the
	linkedlist are inserted alternately to the nodes from the first half in the reverse order.

	So, if the linkedlist has nodes 1 -> 2-> 3 -> 4-> 5 -> 6 -> null, your method should return 

	1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

	Your algorithm should not use any extra space, and the input linkedlist should be modified in-place.

-------------------------------------------------------------------------------------------------------------------------------------

In here the algorithm implementation is simple, we just need to reverse the second half of a linked list, and connect it with
the first half alternatively. 

Since this is a LinkedList, some tricky objectives in the implementation, is finding the exact middle by iteration, and passing
the linkedlist head with call by reference using double pointer, and connecting the 2 linkedlists alternatively.


*/


class Node{

public:
	int data;
	Node* next;

	Node(int val){
		data = val;
		next = NULL;
	}

};

void reverseLinkedList(Node** head_ref){

	Node* back = NULL;
	Node* front;

	Node* itr = (*head_ref);

	while(itr){
	
		front = itr -> next;
		itr -> next = back;
		back = itr;

		itr = front;

	}

	(*head_ref) = back;

}

void arrangeLinkedList(Node** head_ref){

	Node* slow = (*head_ref);
	Node* fast = slow -> next;

	// fast = slow -> next, because then we can get the exact middle, for 1,2,3,4,5,6. We need the second head at 4. that's why

	while(fast && fast->next){
		slow = slow -> next;
		fast = fast -> next -> next;
	}

	Node* head_first_half = (*head_ref);
	Node* head_second_half = slow -> next;

	slow -> next = NULL;

	//To end the first linkedlist. Making it tail to be NULL.

	reverseLinkedList(&head_second_half);

	// Rearranging the linkedlist.
	
	Node* temp;

	while(head_first_half || head_second_half){

	if(head_first_half){
		temp = head_first_half -> next;
		head_first_half -> next = head_second_half;
		head_first_half = temp;
		}

	if(head_second_half){
		temp = head_second_half -> next;
		head_second_half -> next = head_first_half;
		head_second_half = temp;
		}
	
	}


}

int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int element;

	Node* head;
	Node* itr;

	int i = 0;

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

	arrangeLinkedList(&head);

	while(head){
		cout << head -> data << " " ;
		head = head -> next;
	}

	return 0;
}