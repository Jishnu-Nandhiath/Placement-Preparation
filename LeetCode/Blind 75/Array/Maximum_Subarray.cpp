class Solution {
public:
    int maxSubArray(vector<int>& nums) {
   
       int largestSum = INT_MIN, currentSum = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            
            currentSum = max(currentSum + nums[i], nums[i]);
            largestSum = max(largestSum, currentSum);
            
        }
        
        return largestSum;
        
    }
};