#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,phone_number;
	cin>>N;
	map <string,int> phonebook;
	string Name;
	
	
	for(int i = 0;i<N;i++)
	{
		cin>>Name>>phone_number;
		phonebook.insert({Name,phone_number});
	}
	
	string input_string;
	
	while(cin>>input_string)
	{
		if(phonebook.find(input_string) == phonebook.end())
				cout<<"Not found"<<endl;
		else
			cout<<input_string<<"="<<phonebook[input_string]<<endl;
		
	}
	
		
}
