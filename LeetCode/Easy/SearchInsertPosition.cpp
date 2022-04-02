// Method : Binary Search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size() - 1, l = 0;
        int m;
    while (l <= r) {
        m = l + (r - l) / 2;
  
        if (nums[m] == target)
            return m;

        else if (nums[m] < target)
            l = m + 1;

        else
            r = m - 1;
    }
        if(target > nums[m])
            return m+1;
        return m;
    }
};
