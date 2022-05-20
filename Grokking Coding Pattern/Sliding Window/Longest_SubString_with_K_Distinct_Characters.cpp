#include<bits/stdc++.h>

// #define int long long int
#define F first
#define S second
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl;
#define print1(a) for(auto x : a) cout << x.F << " " << x.S << endl;

using namespace std;

/*

-------------------------------------------------------------------------------------------------------------------------------

Problem Statement: 

Given a string, find the length of the longest substring in it with no more than k distinct characters.

-------------------------------------------------------------------------------------------------------------------------------

*/



/*

It's unnecessary to check whether the dictionary key exist with the current char like in other languages
such as python. Because in C++ assigns all the values to be zero, in a map when it is initialized for the
first time.


-------------------------------------------------------------------------------------------------------------


We're keeping track of the map size or number of key value pairs in the map, inorder to check whether the
given number of required distinct characters has been exceeded or not.

Hash map is always useful in case of duplicates, because we can always keep track of the count, and check
for the distinct values.

------------------------------------------------------------------------------------------------------------

A while loop is used in this case, because the window is a dynamic sliding window.

Because when the third character is added to the map there must be chance that the first added character had more
than one occurence in the list, so, all of those has to be removed one by one. We can also remove all of them
together, but then the windowStart won't be able to get to the correct position, where the current window stands.

We need windowStart to calculate the current length of the window, So a while loop is necessary in this situation.


*/


int longestStringWithGivenDistinctCharacters(string inputString, int k)
{

    int longestStringLength = 0, windowStart = 0;

    map<char, int> stringCharCount;

    int length = inputString.size();

    for(int i = 0; i < length; i++)
    {

        stringCharCount[inputString[i]] += 1;


        while(stringCharCount.size() > k)
        {

            stringCharCount[inputString[windowStart]] -= 1;

            if(stringCharCount[inputString[windowStart]] == 0)
            {
                stringCharCount.erase(inputString[windowStart]);
            }

            windowStart += 1;
        }

        longestStringLength = max(longestStringLength, i - windowStart + 1);

    }

    return longestStringLength;

}


int main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T, k ;

    string inputString;

    cin >> T;

    while(T--)
    {

        cin >> k;

        cin.ignore();

        /*

        cin.ignore() is used to avoid the input reader staying at the second line,
        causing it to read the newline as the inputString. Since getline reads from
        the line at which the inputreader is currently standing on.

        It's always safe to use cin.ignore() before getline()

        */

        getline(cin, inputString);

        cout << longestStringWithGivenDistinctCharacters(inputString, k) << endl;

    }

    return 0;
}