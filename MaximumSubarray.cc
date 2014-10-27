class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int max_ends_here[n];
            for(int i = 0; i < n; i++) {
                if (i == 0) {
                    max_ends_here[i] = A[i];
                } else {
                    if (max_ends_here[i - 1] < 0) {
                        max_ends_here[i] = A[i];
                    } else {
                        max_ends_here[i] = A[i] + max_ends_here[i - 1];
                    }
                }
            }
            int max = INT_MIN;
            for(int i = 0; i < n; i++) {
                if(max < max_ends_here[i])
                    max = max_ends_here[i];
            }
            return max;
        }
};
