class Solution {
    public:
        int singleNumber(int A[], int n) {
            vector<int> result(32, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 32; j++) {
                    result[j] += takebit(A[i], j);
                }
            }

            int result_i = 0;
            for (int i = 0; i < 32; i++) {
                result[i] %= 3;
                result_i |= (result[i] << i);
            }

            return result_i;
        }

        int takebit(int number, int bit_index) {
            return (number & (1 << bit_index)) >> bit_index;
        }

};
