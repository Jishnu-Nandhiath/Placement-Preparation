#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    int swaps = 0;
    for(int i = 0; i < n; i++)
    {
    	for(int j=0;j < n-1; j++)
    	{
    		if(a[j]>a[j+1])
    		{
    			swap(a[j],a[j+1]);
    			swaps++;
			}		
		}
	}
	printf("Array is sorted in %d swaps.\n",swaps);
	cout<<"First Element: "<<a[0]<<endl<<"Last Element: "<<a[n-1];
    // Write Your Code Here
    return 0;
}
