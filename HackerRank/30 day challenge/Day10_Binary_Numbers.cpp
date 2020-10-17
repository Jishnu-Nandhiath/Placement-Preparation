#include<bits/stdc++.h>
using namespace std;

string binary(int decimal)
{
	string binary_value = "";
	for(long int i =  decimal ; i> 0 ; i/=2)
		binary_value += to_string(i%2);
	return binary_value;
}


int main()
{
	int n;
	cin>>n;
	string bin = binary(n);

	int count = 0;
	int consecutive_ones = 0;
	
	for(long int j = stol(bin,nullptr) ; j > 0 ; j/=10 )
	{
		j%10?count+=1:count = 0;
		consecutive_ones = max(consecutive_ones, count);
	}
		
	cout<<consecutive_ones;
	
	return 0;
}
