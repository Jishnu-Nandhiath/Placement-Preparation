#include<bits/stdc++.h>
using namespace std;



int main()
{
int N;
vector<int> socks;

cin>>N;
socks.resize(N);

for(int i = 0 ; i<N ; i++)
	cin>>socks[i];

unordered_map<int, size_t> duplicates;

for(int i=0;i<N;i++)
	duplicates[socks[i]]++;

int count = 0;
for(auto &itr:duplicates)
	count += (itr.second/2);
	
cout<<count;
}
