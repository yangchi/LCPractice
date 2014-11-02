#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            return binarySearchRange(A, 0, n, target);
        }

        vector<int> binarySearchRange(int A[], int start, int end, int target) {
            if(start >= end) {
                return vector<int>({-1, -1});
            }
            if(end - start == 1) {
                if(A[start] == target) {
                    return vector<int>({start, start});
                } else {
                    return vector<int>({-1, -1});
                }
            }
            int mid = start + (end - start) / 2;
            if(A[mid] == target) {
                vector<int> first_half = binarySearchRange(A, start, mid, target);
                vector<int> second_half = binarySearchRange(A, mid, end, target);
                if(first_half[1] != -1) {
                    return vector<int>({first_half[0], second_half[1]});
                } else {
                    return vector<int>({second_half[0], second_half[1]});
                }
            } else if(A[mid] < target) {
                return binarySearchRange(A, mid + 1, end, target);
            } else {
                return binarySearchRange(A, start, mid, target);
            }
        }
};

int main()
{
    Solution sol;
    int input[] = {0,0,0,0,1,2,3,3,4,5,6,6,7,8,8,8,9,9,10,10,11,11};
    vector<int> result = sol.searchRange(input, 22, 0);
    for(auto elem: result) {
        cout << elem << endl;
    }
}
