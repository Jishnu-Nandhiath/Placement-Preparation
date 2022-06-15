/*

Note: bitwise operators will directly work on the integers.

    bitwise xor (^) is the inequality checker, so it will represent binary addition except the (1+1) case. So, & is used for that.

    bitwise and (&) is used to take care of carry, and we're also left shifting the binary as well.
*/


class Solution {
public:
    int getSum(int a, int b) {
        
        if(a == 0 || b == 0)
            return a ^ b;
        
    return getSum(a^b,unsigned(a&b) << 1);
        
    }
};