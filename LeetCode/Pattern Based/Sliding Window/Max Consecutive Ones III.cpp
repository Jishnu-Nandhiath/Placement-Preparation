/*  Dynamic Sliding Window

    https://leetcode.com/problems/max-consecutive-ones-iii/

    Since the array input is binary values, no need to use a map, just keep track of all the ones. and add and remove the ones,
    whenever the sliding window moves accordingly. 

    Just keep track of all the ones count, and also the current window Size

    Time Complexity : O(N) Space Complexity : O(1)


*/



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones = 0, windowStart = 0, longestOne = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                ones += 1;
            while(i - windowStart + 1 - ones > k){
                if(nums[windowStart] == 1)
                    ones -= 1;
                windowStart += 1;
            }
            
            longestOne = max(longestOne, i - windowStart + 1);
            
        }
        
        return longestOne;
    }
};