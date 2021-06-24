class Solution {
public:
    bool isPalindrome(int x) {
      long correct = x;
      long rev = 0;
        
        while(x>0)
        {
            rev = rev*10 + x%10;
            x = x/10;
        }
        if(rev == correct)
            return true;
        return false;
    }
};
