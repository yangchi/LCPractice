class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if(s1.length() + s2.length() != s3.length())
                return false;
            if(s3.empty())
                return true;
            return isInterleaveRecur(s1, 0, s2, 0, s3, 0);
        }

        bool isInterleaveRecur(string s1, int pos1, string s2, int pos2, string s3, int pos3) {
            bool result = false;
            if(s1[pos1] == s3[pos3]) {
                result = isInterleaveRecur(s1, pos1 + 1, s2, pos2, s3, pos3 + 1);
            }
            if(result)
                return true;
            if(s2[pos2] == s3[pos3]) {
                result = isInterleaveRecur(s1, pos1, s2, pos2 + 1, s3, pos3 + 1);
            }
            return result;
        }
};
