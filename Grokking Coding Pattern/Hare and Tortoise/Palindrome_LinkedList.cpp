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

	Given the head of a singly linkedlist, write a method to check if the linkedlist is pallindrome or not.

	Your algorithm should use constant space and the input linkedlist should be in the original form once the algorithm is finished.
	The algorithm should have O(N) time complexity where 'N' is the number of nodes in the linkedlist.

-------------------------------------------------------------------------------------------------------------------------------------

In linkedlist the pass by reference is achieved by double pointer, like Node** head_ref;

here head_ref will point to the memory location of the main head, which will result in connecting us to the original
linked list memory.

And while accessing the original linked list, we need not be using the same name because we're using pointers and the
memory address is stored in the variables. So we're accessing the main head pointer via it's address which makes us to
access the original linked list.

So, the variable name difference in user-defined function and main function doesn't matter.

Double pointer is a interesting concept, do read about it if you forgot it again. Use this link

https://www.quora.com/What-is-the-difference-between-node*-and-node**-When-should-I-use-node*-and-when-should-I-use-node**-to-insert-node-in-a-linked-list

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

	// cout << &(*head_ref);

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

bool solve(Node* head){

	Node* slow = head;
	Node* fast = head;

	/*if no of nodes is odd, slow is exact mid, if it is even, slow is the second middle
	node, 1 2 3 4 5 6, slow = 4

	For 1,2,3,3,2,1

	first half will be, 1 -> 2 -> 3 -> 3 -> NULL,
	second half will be , 1 -> 2 -> 3 -> NULL

	the loop breaks when the second half reaches null, and no mismatch will be found.

	for 1,2,3,2,1

	first half will be , 1 -> 2 -> 3 -> NULL
	second half will be, 1 -> 2 -> 3 -> NULL

	We don't necessarily need to find the length of the chain, to just solve the problem.
	It need not be handled.

	*/

	while(fast && fast -> next){
		slow = slow -> next;
		fast = fast -> next -> next;
	}

	reverseLinkedList(&slow);

	Node* head_second_half = slow;

	while(head && head_second_half){
		if(head -> data != head_second_half -> data){
			return false;
		}

		head = head -> next;
		head_second_half = head_second_half -> next;
	}

	return true;

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

	cout << solve(head);


	return 0;
}