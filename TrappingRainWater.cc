class Solution {
    public:
        int trap(int A[], int n) {
            if(n == 0)
                return 0;
            vector<int> max_index_on_left(n, 0), max_index_on_right(n, n - 1);
            for(int i = 1; i < n; i++) {
                if(A[i] > A[max_index_on_left[i - 1]]) {
                    max_index_on_left[i] = i;
                } else {
                    max_index_on_left[i] = max_index_on_left[i - 1];
                }
            }
            for(int i = n - 2; i >=0; i--) {
                if(A[i] > A[max_index_on_right[i + 1]]) {
                    max_index_on_right[i] = i;
                } else {
                    max_index_on_right[i] = max_index_on_right[i + 1];
                }
            }
            int water = 0;
            for(int i = 0; i < n; i++) {
                if(max_index_on_left[i] == i || max_index_on_right[i] == i) {
                    continue;
                } else {
                    int max_left = A[max_index_on_left[i]];
                    int max_right = A[max_index_on_right[i]];
                    water += min(max_left, max_right) - A[i];
                }
            }
            return water;
        }
};
