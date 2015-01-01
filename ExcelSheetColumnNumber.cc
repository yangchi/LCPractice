class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(auto cha : s) {
            int current = toupper(cha) - 'A' + 1;
            result = result * 26 + current;
        }
        return result;
    }
};
