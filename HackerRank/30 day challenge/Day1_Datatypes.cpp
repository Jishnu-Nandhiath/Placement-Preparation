#include<bits/stdc++.h>
using namespace std;

int main()
{
	int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    
    int a;
    double b;
    string input_string;
    
    cin>>a>>b;
    
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    getline(cin,input_string);
    
    input_string =  s + input_string;
    
    printf("%d\n%.1f\n%s",a+i,d+b,input_string.c_str());
    
    
    return 0;
}
