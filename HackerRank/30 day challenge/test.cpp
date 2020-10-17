#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> tester;
	int A;
	tester.resize(5);
	for(int i = 0; i<5 ; i++)
		tester[i] = i;
	A = accumulate(tester.begin(),tester.begin()+3,0) + accumulate(tester.begin()+1,tester.end(),0);
	cout<<A;
}
