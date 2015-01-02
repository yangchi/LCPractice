#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 3) {
            return n;
        }
        int write_index = 2, read_index = 2;
        while(read_index < n) {
            if (A[write_index - 2] != A[read_index]) {
                A[write_index++] = A[read_index];
            }
            read_index++;
        }
        return write_index;
    }
};

int main()
{
    Solution sol;
    int input[3] = {1, 1, 1};
    cout << sol.removeDuplicates(input, 3) << endl;
}
