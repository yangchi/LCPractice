
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ways(s.size(), 0);
        if(s.empty())
            return 0;
        if(s.size() == 1 && s == "0")
            return 0;
        if(s[s.size()-1] == '0')
            ways[s.size()-1] = 0;
        else
            ways[s.size()-1] = 1;
        if(s.size() > 1)
        {
            if(s[s.size()-1] == '0' && s[s.size()-2] > '2')
                return 0;
            if(s[s.size()-2] == '0')
                ways[s.size()-2] = 0;
            else if(s[s.size()-2] == '1' && s[s.size()-1] > '0' || s[s.size()-2] == '2' && s[s.size()-1] > '0' && s[s.size()-1] < '7')
                ways[s.size()-2] = 2;
            else
                ways[s.size()-2] = 1;
        }
        for(int i = s.size()-3; i >=0; i--)
        {
            if(s[i+1] == '0' && s[i] > '2')
                return 0;
            if(s[i] == '0')
                ways[i] = 0;
            else if(s[i+1] > '0' && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
                ways[i] = ways[i+1] + ways[i+2];
            else if(s[i+1] == '0' && (s[i] == '1' || s[i] == '2'))
                ways[i] = ways[i+2];
            else
                ways[i] = ways[i+1];
        }
        return ways[0];
    }        
};
