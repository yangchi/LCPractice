class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> parens;
        map<char, char> rule = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for(auto paren: s)
        {
            if(parens.empty())
                parens.push(paren);
            else if(rule.find(parens.top()) != rule.end()) //top is left paren
            {
                if(rule.find(paren) != rule.end()) //paren is also left
                {
                    parens.push(paren);
                }
                else if(rule.find(parens.top())->second != paren) //violation
                    return false;
                else
                    parens.pop();
            }
            else
                return false;
        }
        if(parens.empty())
            return true;
        return false;
    }
};