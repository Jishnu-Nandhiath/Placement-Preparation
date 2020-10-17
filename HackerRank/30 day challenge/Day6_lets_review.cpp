#include<bits/stdc++.h>
using namespace std;


int main() {
	int T;
	string input_string;
	
	cin>>T;
	
	
	while(T--)
	{
		cin>>input_string;
		
		int n = input_string.length();
		
		char char_array[n+1];
		
		cout<<"c_str func output"<<input_string.c_str()<<endl;
		
		strcpy(char_array,input_string.c_str());
		
		string even_place;
		string odd_place;
		
		for(int i = 0; i<n ; i++)
		{
			if(i%2)
				odd_place += char_array[i];
			else
				even_place +=  char_array[i];
		}
		
	cout<<even_place<<" "<<odd_place<<endl;
	}
	
    return 0;
}

