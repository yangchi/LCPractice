class Solution {
    public:
        void rotate(int nums[], int n, int k) {
            k %= n;
            if (k <= 0) {
                return;
            }

            reverse(nums, nums + n - k);
            reverse(nums + n - k, nums + n);
            reverse(nums, nums + n);
        }
};
