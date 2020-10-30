#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
//Write your code here
class Calculator
{
public:
	int power(int n,int p)
	{
		if(p<0 || n<0)
		{
			throw runtime_error("n and p should be non-negative");
		}
		else
		{
			return pow(n,p);
		}
	return 0;
		}
		
};


int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}
