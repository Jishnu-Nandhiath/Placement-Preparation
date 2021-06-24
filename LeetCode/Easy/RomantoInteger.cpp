class Solution {
public:
    int romanToInt(string s) {
        map<char,int> romans;
        romans['I'] = 1;
        romans['V'] = 5;
        romans['X'] = 10;
        romans['L'] = 50;
        romans['C'] = 100;
        romans['D'] = 500;
        romans['M'] = 1000;
        int out = 0,prev = 0;
        for(int i = s.length() - 1 ; i >= 0 ; i--)
        {
            if(romans[s[i]] < prev)
            {
                out = out - romans[s[i]];
            }
            else{
                out = out + romans[s[i]];
            }
            prev = romans[s[i]];
        }
        return out;
    }
};
