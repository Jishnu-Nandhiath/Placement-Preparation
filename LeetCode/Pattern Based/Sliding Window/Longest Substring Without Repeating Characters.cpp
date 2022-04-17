
/* Dynamic Sliding Window with Hash Map

    A dynamic sliding window keeping track of the elements it swept through in a map, and removing the elements if it already 
    exists inside the map. 

    while loop is to move the start pointer for a case like

    gabcade: here the largest window is bcade, so once the a at the 5th position is discovered we need to iterate to make the 
    pointer to reach the letter b. 

    For almost all the dynamic sliding window a while loop is requierd within the for loop. 

    https://leetcode.com/problems/longest-substring-without-repeating-characters/

*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int windowStart = 0, length = 0;
        
    map<char,int> frequencyMap;
        
    for(int i = 0; i < s.length(); i++){
        
        while(frequencyMap.find(s[i]) != frequencyMap.end() && windowStart <= i){
        
            if(--frequencyMap[s[windowStart]] == 0)
                frequencyMap.erase(s[windowStart]);
        
            windowStart += 1;
        
        }
        
        frequencyMap[s[i]]++;
        length = max(length, i - windowStart + 1);
    }
        return length;
    }
};