class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            if(m == 0) {
                if(n%2 == 1)
                    return B[n/2];
                else
                    return (B[n/2] + B[n/2 - 1])/2.0;
            }
            if(n == 0) {
                if(m%2 == 1) {
                    return A[m/2];
                } else {
                    return (A[m/2] + A[m/2 - 1])/2.0;
                }
            }
            if(n == 1 and m == 1) {
                return (A[0] + B[0]) / 2.0;
            }
            if((m + n) % 2 == 0) {
                int first = findKthSmallest(A, 0, m, B, 0, n, (m + n)/2);
                int second = findKthSmallest(A, 0, m, B, 0, n, (m + n)/2 - 1);
                return (first + second) / 2.0;
            } else {
                return findKthSmallest(A, 0, m, B, 0, n, (m + n)/2);
            }
        }

        int findKthSmallest(int A[], int startA, int endA, int B[], int startB, int endB, int k) {
            int lengthA = endA - startA;
            int lengthB = endB - startB;
            if(lengthA == 0) {
                return B[startB + k];
            }
            if(lengthB == 0) {
                return A[startA + k];
            }

            int forward = 0;
            int indexA = startA, indexB = startB;
            if (lengthA > lengthB) {
                forward = (int)ceil(((double)lengthA * k / (lengthA + lengthB)));
                indexA += forward;
                indexB += (k - forward);
            } else {
                forward = (int)ceil(((double)lengthB * k / (lengthA + lengthB)));
                indexB += forward;
                indexA += (k - forward);
            }
            int valueA_prev = indexA > startA ? A[indexA - 1] : INT_MIN;
            int valueB_prev = indexB > startB ? B[indexB - 1] : INT_MIN;
            int valueA = indexA < endA ? A[indexA] : INT_MAX;
            int valueB = indexB < endB ? B[indexB] : INT_MAX;
            if(valueA >= valueB_prev && valueA <= valueB) {
                return valueA;
            } else if(valueB >= valueA_prev && valueB <= valueA) {
                return valueB;
            } else if(valueA < valueB_prev) {
                return findKthSmallest(A, indexA + 1, endA, B, startB, indexB, k - (indexA - startA) - 1);
            } else {
                return findKthSmallest(A, startA, indexA, B, indexB + 1, endB, k - (indexB - startB) - 1);
            }
        }
};
