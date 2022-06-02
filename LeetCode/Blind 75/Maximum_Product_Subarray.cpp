/*  This is a sample of Kadane's algorithm.

Since the product of 2 negative numbers can be positive, we need to keep track of the minimum product and maximum
product in 2 different variables until the iteration point, and keep checking the combination of product of all these.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0], prod2 = nums[0],temp ;
        int result = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
        
            temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
            prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
            prod1 = temp;
            
            
            // cout<< prod1 <<endl<<prod2<<endl;
            
            result = max(result,prod1);
            
        }
        return result;
    }
};