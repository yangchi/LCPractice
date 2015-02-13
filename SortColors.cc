class Solution {
    public:
        void sortColors(int A[], int n) {
            int red_index = 0;
            int blue_index = n - 1;
            int current = 0;
            while (current <= blue_index) {
                if (A[current] == 0) {
                    swap(A, red_index, current);
                    red_index++;
                    current++;
                } else if (A[current] == 2) {
                    swap(A, blue_index, current);
                    blue_index--;
                } else {
                    current++;
                }
            }
        }

        void swap(int A[], int first, int second) {
            int temp = A[first];
            A[first] = A[second];
            A[second] = temp;

        }
};
