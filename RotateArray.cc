class Solution {
    public:
        void rotate(int nums[], int n, int k) {
            k %= n;
            if (k <= 0) {
                return;
            }
            int temp[n];
            for (int i = 0; i < k; i++) {
                temp[i] = nums[n - k + i];
            }

            for (int i = k; i < n; i++) {
                temp[i] = nums[i - k];
            }

            for (int i = 0; i < n; i++) {
                nums[i] = temp[i];
            }
        }
};
