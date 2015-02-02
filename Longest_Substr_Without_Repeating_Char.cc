class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0;
        int length = 0;
        int longest = 0;
        vector<int> positions(256, -1);
        while(index < s.size()) {
            char curr_c = s[index];
            if (positions[curr_c] == -1) {
                length++;
                positions[curr_c] = index++;
            } else {
                //existing
                index = positions[curr_c] + 1;
                for (auto & c : positions) {
                    c = -1;
                }
                if (length > longest) {
                    longest = length;
                }
                length = 0;
            }
        }
        if (length > longest) {
            longest = length;
        }
        return longest;
    }
};
