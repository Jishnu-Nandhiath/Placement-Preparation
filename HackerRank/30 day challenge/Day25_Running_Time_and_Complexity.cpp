#include<bits/stdc++.h>
using namespace std;


int main() {

// algorithm used in here is known as sieve of Eratosthenes.

    int T,n;


    cin>>T;
    while(T--)
    {

    cin>>n;
    if(n==1)
        {
            cout<<"Not prime"<<endl;
            continue;
        }
    else if( n==2 )
        {
            cout<<"Prime"<<endl;
            continue;
        }
    for(int i =2; i<=ceil(sqrt(n)); i++)
    {
        if(n%i == 0)
            {
                cout<<"Not prime"<<endl;
                break;
            }
        else if(i == ceil(sqrt(n)))
            cout<<"Prime"<<endl;

    }

    }

    return 0;
}
