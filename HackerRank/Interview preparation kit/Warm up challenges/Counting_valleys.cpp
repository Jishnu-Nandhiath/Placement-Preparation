#include<bits/stdc++.h>
using namespace std;

int main()
{
	int steps,level = 0,valleys = 0;
	string path;
	
	cin>>steps>>path;
	
	for(int i = 0; i<steps; i++)
	{
		path[i]=='U'?level+=1:level-=1;
		if(path[i]=='U' && level == 0)
			valleys++;
		
	}
	cout<<valleys;
	
return 0;
}
