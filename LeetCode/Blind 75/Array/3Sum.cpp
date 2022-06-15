class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> triplets;
        
        if(nums.size() < 3){
            return triplets;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i <= nums.size() - 3; i++){
            
            if(i == 0 || nums[i] != nums[i - 1]){
                
                int left = i + 1, right = nums.size() - 1;
            
            
            while(left < right){
                
                int currSum = nums[i] + nums[left] + nums[right];
                
                if(currSum == 0){
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left += 1;
                    
                while(nums[left] == nums[left - 1] && left < right){
                    left += 1;
                }
                /*
    
                To avoid duplicates, once a target triplet has been found, one of the pointers are moved out of the duplicates,
                because duplicates are adjacent since the array is sorted.
                
                */
                    
                }
                
                
                if(currSum > 0){
                    right -= 1;
                }else if(currSum < 0){
                    left += 1;
                }
            }
                
            }
                        
        }
        
        return triplets;
        
    }
};