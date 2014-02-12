class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() == 1)
            return s;
        string max_str("");
        int max = 0;
        bool PalindromeMatrix[s.size()+1][s.size()+1];
        for(int len = 1; len <= s.size(); len++)
        {
            for(int pos = 0; pos <= s.size()-len; pos++)
            {
                if(len == 1)
                    PalindromeMatrix[pos][pos+len] = true;
                else if(len == 2)
                    PalindromeMatrix[pos][pos+len] = s[pos] == s[pos+len-1];
                else
                    PalindromeMatrix[pos][pos+len] = PalindromeMatrix[pos+1][pos+len-1] && (s[pos] == s[pos+len-1]);
                if(PalindromeMatrix[pos][pos+len])
                    if(len > max)
                    {
                        max = len;
                        max_str = s.substr(pos, len);
                    }
            }
        }
        return max_str;
    }
};