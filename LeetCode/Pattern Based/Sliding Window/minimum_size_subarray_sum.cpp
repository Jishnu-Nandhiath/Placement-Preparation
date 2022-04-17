/* https://leetcode.com/problems/minimum-size-subarray-sum/

	Sliding Window : medium , flexible window Size Needs to move if the current window is larger than the previous window, 
	and if it still satisfies the required condition, and returns 0 if the condition is not met for any subarray at all.


	while loop is given if the iteration meets some large element in the array, the condition will be met if multiple elements 
	from the window are still removed. This is why it is given. */


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int windowStart = 0, windowSum = 0, windowSize = INT_MAX;
        int flag = 0;
        for(int i = 0; i < nums.size(); i++){
            windowSum += nums[i];
            
            while(windowSum >= target){
                flag = 1;
                windowSize = min(i - windowStart + 1, windowSize);
                windowSum -= nums[windowStart];
                windowStart += 1;
            }
        }
        
        if(flag == 0)
            return 0;
        
        return windowSize;
    }
};