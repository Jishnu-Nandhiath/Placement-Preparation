class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> output(nums.size());
        int product = 1;
        
        int zeroCount = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i]){
                product *= nums[i];
            }else{
                zeroCount += 1;
            }

            
        }
        

        /*
        
        The order at which the if else statements are written is also important in this case.

        The tricky part of this question is where 0 comes in, and also the case of more than 1 zeros.
    
        */

        for(int i = 0; i < nums.size(); i++){
            
            if(zeroCount > 1){
                output[i] = 0;
            }else if(zeroCount && nums[i]){
                output[i] = 0;
            }else if(!nums[i] && zeroCount){
                output[i] = product;
            }else{
                output[i] = (product/nums[i]);
            }
            

        }

    return output;
        
    }
};