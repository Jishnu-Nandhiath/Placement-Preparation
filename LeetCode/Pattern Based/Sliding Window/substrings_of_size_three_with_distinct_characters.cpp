/* sliding window Pattern of fixed sized window

https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

* Since, no repeating characters are allowed, keep track of count of all the char in the string,

* And once the window size and map length matches, Increase the count,

* No need to check for the existance of characters in the map, because if the size of the map is equal to 3, 

* Then the window only contains 3 unique characters, and once the window size matches

* Remove the characters if the map size is not 3. 

*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int windowStart = 0, count = 0;
        map<char,int> charTracker;
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
        
            charTracker[s[windowEnd]]++;
                        
            if(windowEnd - windowStart + 1 == 3){
                if(charTracker.size() == 3)
                    count++;
                if(--charTracker[s[windowStart]] == 0)
                    charTracker.erase(s[windowStart]);
                windowStart += 1;
            }
            
        }
        return count;
    }
};