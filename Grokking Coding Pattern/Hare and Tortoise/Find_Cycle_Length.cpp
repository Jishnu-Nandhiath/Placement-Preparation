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
		this -> data = 0;
		this -> next = NULL;
	}

	Node(int data){
		this -> data = data;
		this -> next = NULL;
	}

};



int solve(Node* head){
	
	Node *slow = head;
	Node *fast = head;


	while(fast -> next != NULL && fast != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;

		if(slow == fast){
			break;
		}

		// cout <<1;
	}

	// cout << 1;

	int cycleLength = 0;

	// slow = slow -> next;

	while(true){
		slow = slow -> next;
		cycleLength += 1;

		if(slow == fast){
			break;
		}
	}



	return cycleLength;

}




int main(){
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int inputElement;

	Node *itr;

	int i = 0;

	Node *head;

	while(cin >> inputElement){

		Node* current = new Node(inputElement);

		if(i == 0){
			head = current;
		}else{
			itr -> next = current;
		}

		itr = current;

		i += 1;

	}


	head -> next -> next -> next -> next = head -> next;

	// itr = head;

	// while(itr){
	// 	cout << itr -> data << " ";
	// 	itr = itr -> next;
	// }

	cout << solve(head);


	return 0;
}