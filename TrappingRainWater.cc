class Solution {
    public:
        int trap(int A[], int n) {
            vector<int> curmaxleft(n, INT_MIN), curmaxright(n, INT_MIN);
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    curmaxleft[i] = A[i];
                } else {
                    curmaxleft[i] = max(curmaxleft[i - 1], A[i]);
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                if (i == n - 1) {
                    curmaxright[i] = A[i];
                } else {
                    curmaxright[i] = max(curmaxright[i + 1], A[i]);
                }
            }

            int rain = 0;
            for (int i = 0; i < n; i++) {
                rain += min(curmaxleft[i], curmaxright[i]) - A[i];
            }
            return rain;
        }
};
