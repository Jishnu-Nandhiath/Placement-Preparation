#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a_count = 0;
    string s;
  	long size = s.length();
	long repetition = n/size;
  	long left = n - (size * repetition);
  	
    cin>>s>>n;
    
    size_t a_in_substring = count(s.begin(),s.end(),'a');

    a_count = repetition * a_in_substring;

    size_t extra = count(s.begin(),s.end() - (s.length() - left),'a');

    a_count += extra;
    
    cout<<a_count;
    
    return 0;
}
