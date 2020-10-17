 #include<bits/stdc++.h>
 using namespace std;
 
  main(){
 		
 	/***          Pointers in the case of variables      ********/	
 		
 		int a =4 ;
 		int *p = &a; // pointer initialisation
 	
 		cout<< p<<endl; //printing the a's address
 		cout<<&a<<endl; //printing the a's address
 		cout<<*p<<endl; //printing the value in 'a, called dereferencing
 		cout<<a; 
 		cout<<&p<<endl; //print the address location of the pointer variable stored in
 		*p =8; //updating the value in a with pointers
 		cout<<a;
  }
