
/*  Dynamic Sliding Window

https://leetcode.com/problems/longest-repeating-character-replacement/

The code simply keep track of all the frequency count of all the char in the input string, and also keep track of the
count of the most repeating character in the input string window. 

For questions like these if we just need to return the count for the longest string, don't even try to bother about 
replacing the char or modifying the string, it will never be required to just return the count in such cases.

Only do such modifications if the output of the code specifies any such details. 

i - windowStart + 1 : will return the size of the window. when we subtract the mostRepeatingCharCount from the windowSize,
the value should not excced the k. This verifies whether or not k replacements has been done or not. 


*/



class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0, windowStart = 0;
        map<char, int> frequencyMap;
        
        int maxRepeatingCharCount = 0;
        
        for(int i = 0; i < s.length(); i++){
            frequencyMap[s[i]]++;
                
            maxRepeatingCharCount = max(maxRepeatingCharCount, frequencyMap[s[i]]);
            
            if(i - windowStart + 1 - maxRepeatingCharCount > k){
                --frequencyMap[s[windowStart]];
                windowStart += 1;
            }
            length = max(length, i - windowStart + 1);
        }
        return length;
    }
    
};