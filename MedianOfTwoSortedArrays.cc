#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m == 0) {
            cout << "A is empty" << endl;
            if(n%2 == 1)
                return B[n/2];
            else
                return (B[n/2] + B[n/2 - 1])/2.0;
        }
        if(n == 0) {
            cout << "B is empty" << endl;
            if(m%2 == 1) {
                return A[m/2];
            } else {
                return (A[m/2] + A[m/2 - 1])/2.0;
            }
        }

        if((m + n) % 2 == 0) {
            cout << "Even number first: " << endl;
            int first = findKthSmallest(A, 0, m, B, 0, n, (m + n)/2);
            cout << "first: " << first << endl;
            cout << "Even number second: " << endl;
            int second = findKthSmallest(A, 0, m, B, 0, n, (m + n)/2 - 1);
            cout << "second: " << second << endl;
            return (first + second) / 2.0;
        } else {
            cout << "Odd number" << endl;
            return findKthSmallest(A, 0, m, B, 0, n, (m + n)/2);
        }
    }
    
    int findKthSmallest(int A[], int startA, int endA, int B[], int startB, int endB, int k) {
        cout << "Finding " << k << " " << startA << " " << endA << " " << startB << " " << endB << endl;
        int lengthA = endA - startA;
        int lengthB = endB - startB;
        if(lengthA == 0) {
            if(lengthB % 2 == 1)
                return B[lengthB / 2];
            else
                return (B[lengthB / 2] + B[lengthB / 2 - 1]) / 2;
        }
        if(lengthB == 0) {
            if (lengthB %2 == 1)
                return A[lengthA / 2];
            else
                return (A[lengthA / 2] + A[lengthA / 2 - 1]) / 2;
        }
        if (lengthA == 1 && lengthB == 1) {
            return(A[startA] + B[startB]) / 2.0;
        }
        int indexA = (int)((double)k * lengthA / (lengthA + lengthB));
        int indexB = k - indexA;
        cout << "index: " << indexA << " " << indexB << endl;
        int valueA_prev = indexA > startA ? A[indexA - 1] : INT_MIN;
        int valueB_prev = indexB > startB ? B[indexB - 1] : INT_MIN;
        int valueA = indexA < endA ? A[indexA] : INT_MAX;
        int valueB = indexB < endB ? B[indexB] : INT_MAX;
        cout << valueA_prev << " " << valueA << " " << valueB_prev << " " << valueB << endl;
        if(valueA >= valueB_prev && valueA <= valueB) {
            cout << "Case 1" << endl;
            return valueA;
        } else if(valueB >= valueA_prev && valueB <= valueA) {
            cout << "CAse 2" << endl;
            return valueB;
        } else if(valueA < valueB_prev) {
            cout << "Case 3" << endl;
            return findKthSmallest(A, indexA, endA, B, startB, indexB, k - indexA );
        } else {
            cout << "CAse 4" << endl;
            return findKthSmallest(A, startA, indexA, B, indexB, endB, k - indexB );
        }
    }
};

int main()
{
    Solution sol;
    int A[] = {1, 3};
    int B[] = {2};
    cout << sol.findMedianSortedArrays(A, 2, B, 1) << endl;
}
