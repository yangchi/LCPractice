class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if (n == 0) {
                return 0;
            }
            int read_i = 1, write_i = 1;
            while(read_i < n) {
                if (A[read_i] != A[write_i - 1]) {
                    A[write_i++] = A[read_i++];
                } else {
                    read_i++;
                }
            }
            return write_i;
        }
};
