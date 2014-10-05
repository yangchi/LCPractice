class Solution {
    public:
        int maxProduct(int A[], int n) {
            if(n == 0)
                return 0;
            if (n == 1)
                return A[0];
            vector<int> maxUntil(n, 1);
            vector<int> minUntil(n, 1);
            int maxprd = A[0];
            maxUntil[0] = A[0];
            minUntil[0] = A[0];
            for(int i = 1; i < n; i++) {
                maxUntil[i] = max(maxUntil[i-1] * A[i], minUntil[i-1] * A[i]);
                maxUntil[i] = max(maxUntil[i], A[i]);
                minUntil[i] = min(maxUntil[i-1] * A[i], minUntil[i-1] * A[i]);
                minUntil[i] = min(minUntil[i], A[i]);
                maxprd = max(maxprd, maxUntil[i]);
            }
            return maxprd;
        }
};
