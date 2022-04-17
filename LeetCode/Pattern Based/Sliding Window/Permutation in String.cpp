/* Fixed Sliding Window with HashMap

https://leetcode.com/problems/permutation-in-string/





*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<char,int> frequencyMap;
        int windowStart = 0, matched = 0;
        
        for(int i = 0; i < s1.length(); i++){
            frequencyMap[s1[i]]++;
        }
        
        for(int i = 0; i < s2.length(); i++){
            
            if(i > s1.length() - 1){
                if(frequencyMap.find(s2[windowStart]) != frequencyMap.end()){
                    if(frequencyMap[s2[windowStart]] == 0)
                        matched -= 1;
                    frequencyMap[s2[windowStart]]++;
                }
                windowStart += 1;
            }
            
            
            if(frequencyMap.find(s2[i]) != frequencyMap.end()){
                frequencyMap[s2[i]]--;
                if(frequencyMap[s2[i]] == 0)
                    matched += 1;
            }
            
            if(matched == frequencyMap.size())
                return true;
        }
        return false;
        
    }
};