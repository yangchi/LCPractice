class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }

            string str_x = to_string(x);
            /*if (str_x.size() % 2 == 1) {
             *             return false;
             *                     }
             *                             */
            int index = 0;
            while (index < str_x.size() / 2) {
                char current = str_x[index];
                if (current != str_x[str_x.size() - 1 - index]) {
                    return false;
                } else {
                    index++;
                }
            }

            return true;
        }
};
