class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return longestContainedFromPos(s, 0);
    }
    
    int longestContainedFromPos(string s, int pos) {
        if((s.length() - pos) < 2)
            return s.length() - pos;
        else{
            int max1 = longestFromPos(s, pos);
            int max2 = longestContainedFromPos(s, pos+1);
            return max1 > max2 ? max1: max2;
        }
    }
    
    int longestFromPos(string s, int pos){
        string temp;
        int length = 0;
        for(int i = pos; i < s.length(); i++){
            if(temp.find(s[i]) != string::npos)
                return length;
            else{
                temp.append(1, s[i]);
                length++;
            }
        }
        return length;
    }
};