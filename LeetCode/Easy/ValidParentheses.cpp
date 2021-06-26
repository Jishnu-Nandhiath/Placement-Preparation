#include<string>
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for(int i = 0 ; i < s.size(); i++ )
        {
            switch(s[i])
            {
                case '{':
                case '[':
                case '(':
                    bracket.push(s[i]);
                    break;
                case ')':
                    if(bracket.empty() || bracket.top() != '(')
                        return false;
                    bracket.pop();
                    break;
                case ']':
                    if(bracket.empty() || bracket.top() != '[')
                        return false;
                    bracket.pop();
                    break;
                case '}':
                    if(bracket.empty() || bracket.top() != '{')
                        return false;
                    bracket.pop();
                    break;
                 
            }
        }
        if(bracket.empty())
            return true;
        return false;
    }
};
