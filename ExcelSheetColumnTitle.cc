class Solution {
    public:
        string convertToTitle(int n) {
            string result = "";
            while (n) {
                result = (char)('A' + (n - 1) % 26) + result;
                n = (n - (n - 1) % 26) / 26;
            }
            return result;
        }
};
