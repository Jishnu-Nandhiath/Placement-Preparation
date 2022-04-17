/* Similar to sliding window :
    
    No specified fixed length for the sliding window, window Size needs to be flexible,
    In here window moves, if the current sum is less than the current element value. 

    compare the current Sum with current element, since the array contains negative integers.

    And compare the current Sum and the largest Sum to get the largest Sum.

    Time Complexity is O(N). Space Complexity O(1) : No extra space is used. 

    https://leetcode.com/problems/maximum-subarray

    */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
   
       int largestSum = -INT_MAX, windowStart = 0, currentSum = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            
            currentSum = max(currentSum + nums[i], nums[i]);
            largestSum = max(largestSum, currentSum);
            
        }
        
        return largestSum;
        
    }
};