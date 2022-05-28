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

	Given the head of a singly linkedlist that contains a cycle, write a function to find the starting node of the cycle.

-------------------------------------------------------------------------------------------------------------------------------------

The implementation is pretty simple. First we find the length of the cycle, then we create 2 pointers in which one is
starting from the head, and other is starting from a distance of the cyclelength from the head. When each pointers jump
one by one, they will eventually meet a the start of the cycle, breaking the loop.

The algorithm works in all the situations, independent of the cycle length or the length of the LinkedList.


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
		this -> data = val;
		this -> next = NULL;
	}
};


int cycleLength(Node* head){

	Node* slow = head;
	Node* fast = head;

	int length = 0;

	while(fast && fast -> next){

		slow = slow -> next;
		fast = fast -> next -> next;

		if(slow == fast){
			
			while(true){

				length += 1;

				slow = slow -> next;

				if(slow == fast){
					return length;
				}
			}

		}

	}
	return length;

}



int startNode(Node* head){

	int length = cycleLength(head);

	Node* lead = head;
	Node* last = head;

	while(length--){
		lead = lead -> next;
	}

	while(lead != last){
		lead = lead -> next;
		last = last -> next;
	}

	return lead -> data;

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

	itr -> next = head -> next;

	cout << startNode(head);


	return 0;
}