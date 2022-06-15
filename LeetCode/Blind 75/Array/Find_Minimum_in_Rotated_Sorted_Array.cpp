/*

------------------------------------------------------------------------------------------------------------

Problem Statement:

    Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.

    You must write an algorithm that runs in O(log n) time.

------------------------------------------------------------------------------------------------------------


Here the array seems to be right rotated, and only contains unique elements.

These are the most important points in the question.

So, we use binary search to achieve O(logN). And here the mid element is compared with both ends.

And if loop first check has to be whether the lowest element is on the right side, because the array is right rotated.

The array may contain a smaller element on the left side but it need not be the lowest element, so the first if check
always has to be done on the right side only.

3 4 5 1 2 : sample case explaining the if condiiton order.


*/




class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1;
        
        int mid, out;
        
        while(left < right){
         
            mid = (left + right) / 2 ;
  
            
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else if(nums[mid] < nums[right]){
                right = mid;
            }else{
                right--; // if right has reached the mid value, we need to keep reducing the array window.
            }
            
        }
        
        return nums[left];
        
    }
};