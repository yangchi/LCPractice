class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool f[s1.size()][s2.size()][s1.size()+1];
        for(auto i = 0; i < s1.size(); i++)
            for(auto j = 0; j < s2.size(); j++)
                for(auto k = 0; k < s1.size()+1; k++)
                    f[i][j][k] = false;
        if(s1.size() != s2.size())
            return false;
        if(s1.empty())
            return true;
        for(auto i = 0; i < s1.size(); i++) {
            for(auto j = 0; j < s2.size(); j++) {
                f[i][j][0] = true;
                f[i][j][1] = s1[i] == s2[j];
            }
        }
        for(auto step = 2; step <= s1.size(); step++) {
            for(auto i = 0; i <= s1.size()-step; i++) {
                for(auto j = 0; j <= s2.size()-step; j++) {
                    for(auto pos = 1; pos < step; pos++) {
                        f[i][j][step] |= f[i][j][pos] && f[i+pos][j+pos][step-pos] || 
                                         f[i][j+step-pos][pos] && f[i+pos][j][step-pos];
                        if(f[i][j][step])
                            break;
                    }
                }
            }
        }
        return f[0][0][s1.size()];
    }
};