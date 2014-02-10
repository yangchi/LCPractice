//TLE
//
class Solution {
    public:
        int minCut(string s) {
            int resultMat[s.size()][s.size()];
            for(int i = 0; i < s.size(); i++)
                for(int j = 0; j < s.size(); j++)
                    resultMat[i][j] = j-i-1;
            for(int i = 0; i < s.size(); i++)
                resultMat[i][i+1] = 0;
            for(int step = 2; step < s.size(); step++)
            {
                for(int pos = 0; pos + step <= s.size(); pos++)
                {
                    if(isPalindrome(s, pos, step+pos))
                        resultMat[pos][step+pos] = 0;
                    else
                    {
                        for(int cutpos = pos+1; cutpos < pos+step; cutpos++)
                            resultMat[pos][step+pos] = min(1+resultMat[pos][step+pos], resultMat[pos][cutpos]);
                    }
                }
            }
            return resultMat[0][s.size()];
        }

        bool isPalindrome(string s, size_t begin, size_t end)
        {
            if(end < begin)
                return false;
            for(int i = begin; i < end; i++)
            {
                if(s[begin+i] != s[end-i-1])
                    return false;
            }
            return true;
        }
};
