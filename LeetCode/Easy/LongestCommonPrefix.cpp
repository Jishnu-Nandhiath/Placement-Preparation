class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prev_pref = "", pref = "";
        for(int i = 0; i < strs.size() ; i++ )
        {
            pref = "";
            if(i==0)
            {
                prev_pref = strs[0];
                pref = prev_pref;
                continue;
            }
            for(int j = 0 ; j < min(strs[i].length(),prev_pref.length()); j++)
            {
                if(strs[i][j] == prev_pref[j])
                {
                    pref += prev_pref[j]; 
                }
                else{
                    prev_pref = pref;
                    break;
                }
            }
            prev_pref = pref;
        }
        return pref;
        
    }
};
