#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int index = digits.size() - 1;
            while(index >= 0) {
                if (digits[index] == 9) {
                    digits[index--] = 0;
                } else {
                    digits[index]++;
                    break;
                }
            }
            if (digits[0] == 0) {
                vector<int> result(digits.size() + 1, 0);
                result[0] = 1;
                return result;
            } else {
                return digits;
            }
        }
};

int main()
{
    vector<int> input = {9, 9};
    Solution sol;
    vector<int> output = sol.plusOne(input);
    for(auto elem : output) {
        cout << elem << " ";
    }

    cout << endl;
}
