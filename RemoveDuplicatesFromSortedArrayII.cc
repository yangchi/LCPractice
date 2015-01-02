#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 3) {
            return n;
        }
        map<int, int> number_counter;
        int index = 0, new_size = 0;
        while(index < n) {
            if (number_counter.find(A[index]) == number_counter.end()) {
                number_counter[A[index]] = 1;
                A[new_size++] = A[index++];
            } else if (number_counter[A[index]] < 2) {
                number_counter[A[index]]++;
                A[new_size++] = A[index++];
            } else {
                index++;
            }
        }
        return new_size;
    }
};

int main()
{
    Solution sol;
    int input[3] = {1, 1, 1};
    cout << sol.removeDuplicates(input, 3) << endl;
}
