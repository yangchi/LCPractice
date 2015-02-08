class Solution {
    public:
        int reverse(int x) {
            bool negative = x < 0;
            if (negative) {
                x = -x;
            }

            int result = 0;
            while (x > 0) {
                if (result > INT_MAX / 10) {
                    return 0;
                }

                result = result * 10 + x % 10;
                x /= 10;
            }

            if (negative) {
                return -result;
            } else {
                return result;
            }
        }
};
