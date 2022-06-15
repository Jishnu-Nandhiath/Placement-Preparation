/*

2 Pointer Approach

*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int currArea = 0;
        int maxArea = 0;
        
        while(left < right){
            currArea = min(height[left], height[right]) * (right - left);
            
            maxArea = max(maxArea, currArea);
            
                if(height[left] < height[right]){
                    left += 1;
                }else{
                    right -= 1;
                }
        }
        
        return maxArea;
        
    }
};