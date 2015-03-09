class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t result = 0;
            for (int i = 0; i < 32; i++) {
                uint8_t current = takeNth(n, i);
                result <<= 1;
                result |= current;
            }
            return result;
        }

        uint8_t takeNth(const uint32_t input, int n) {
            return (input & (1 << n)) >> n;
        }
};
