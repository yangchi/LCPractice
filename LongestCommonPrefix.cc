class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.empty())
                return "";
            char current = '\0';
            int index = 0;
            string result = "";
            for(index = 0; index < strs[0].size(); index++) {
                for(auto str : strs) {
                    if(current == '\0') {
                        current = str[index];
                    } else {
                        if(str[index] != current)
                            return result;
                    }
                }
                result += current;
                current = '\0';
            }
            return result;
        }
};
