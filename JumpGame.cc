class Solution {
    public:
        bool canJump(int A[], int n) {
            int target = n - 1;
            for(int index = n - 2; index >= 0; index--) {
                if (A[index] + index >= target) {
                    target = index;
                }
            }

            return target == 0;
        }
};
