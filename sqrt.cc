class Solution {
    public:
        int sqrt(int x) {
            int64_t result = 0;
            int bit = 1 << 16;
            while(bit > 0) {
                result |= bit;
                if (result * result > x) {
                    result ^= bit;
                }

                bit >>= 1;
            }

            return (int)result;
        }
};
