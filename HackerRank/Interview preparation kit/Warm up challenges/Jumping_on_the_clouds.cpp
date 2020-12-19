#include<bits/stdc++.h>
using namespace std;

int main()
{

int N,jumps = 0;
vector<int> clouds;

cin>>N;
clouds.resize(N);

for(int i=0; i<N; i++)
    cin>>clouds[i];

for(int i=0; i<N-1 ; )
    {
        clouds[i+1]==1 || clouds[i+2]==0?i+=2:i++;
        jumps+=1;
    }
cout<<jumps;
}

