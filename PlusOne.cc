#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            if (digits.empty()) {
                return vector<int>();
            }
            int index = digits.size() - 1;
            while(index >= 0 && digits[index] == 9) {
                digits[index--] = 0;
            }
            digits[index]++;
            vector<int> result(digits.begin(), digits.end());
            if (result[0] == 0) {
                result.insert(result.begin(), 1);
            }

            return result;
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
