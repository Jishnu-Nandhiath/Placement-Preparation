class Solution {
public:
    int reverse(int x) {
        string pal = "";
        int i = 1;
        if(x<0)
            i = -1;
        x = abs(x);
        while(x > 0)
        {
            pal = pal + to_string(x%10);
            x = x/10;
        }
        try
        {
            return stoi(pal)*i;
        }
        catch(exception)
        {
            return 0;
        }
    }
};
