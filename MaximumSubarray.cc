class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int running[n];
            for(int i = 0; i < n; i++) {
                running[i] = A[i];
            }

            int max_running = INT_MIN;
            for(int i = 0; i < n; i++) {
                if (i != 0 && running[i - 1] > 0) {
                    running[i] += running[i - 1];
                }
                if (max_running < running[i]) {
                    max_running = running[i];
                }
            }
            return max_running;
        }
};
