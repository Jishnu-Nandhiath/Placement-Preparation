class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1, mid = 0;
        
        while(left <= right){
            
          mid = (left + right) / 2;
            
        if(nums[mid] == target){
                return mid;
            }
            
        
        if(nums[mid] >= nums[left]){

            /* 

            The first check is to check whether the lower end of the array is in right half or not.

            Since there may be cases, like 3 4 5 6 7 1 2, Here 6 is the mid, and consider 2 test cases, where we need to
            check for 7 or 1, Seven is greater than mid, one is less than mid. And both are in right half. So a single if
            condition won't work.
        
            */

            if(target >= nums[left] && target <= nums[mid]){
                
                right = mid - 1;
                
            }else{
                
                left = mid + 1;
                
                }
            }
            else{
            
            if(target <= nums[right] && target >= nums[mid]){
                left = mid + 1;
                
            }else{
                
                right = mid - 1;
                
            }
        }
   
                
            }
        return -1;
    }
};