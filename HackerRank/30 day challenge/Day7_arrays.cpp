#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	vector<int> integer_array;
	
	cin>>N;
	integer_array.resize(N);
	
	for(int i = 0; i<N ; i++)
		cin>>integer_array[i];
	
	for(int i = N-1; i>=0 ; i--)
		cout<<integer_array[i]<<" ";
}
