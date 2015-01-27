class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2) {
            return 0;
        }
        int range_start = 0, range_end = 0;
        int counter = 0;
        while (range_end < n) {
            counter++;
            int current_max = 0;
            for(int i = range_start; i <= range_end; i++) {
                if(A[i] + i >= n - 1) {
                    return counter;
                }

                if (A[i] + i > current_max) {
                    current_max = A[i] + i;
                }
            }

            range_start = range_end + 1;
            range_end = current_max; // > range_end + 1 ? current_max : range_end + 1;
        }

        return counter;
    }
};
