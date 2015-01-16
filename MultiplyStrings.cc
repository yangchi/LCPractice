#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> result_integer(num1.size() + num2.size() + 1, 0);
        for(int i = 0; i < num2.size(); i++) {
            int d2 = num2[num2.size() - i - 1] - '0';
            for(int j = 0; j < num1.size(); j++) {
                int d1 = num1[num1.size() - j - 1] - '0';
                int d = d1 * d2 + result_integer[i + j];
                result_integer[i + j] = d % 10;
                result_integer[i + j + 1] += d / 10;;
            }
        }

        string result;
        int index = result_integer.size();
        while(index >= 0 && result_integer[--index] == 0) {
            ;
        }

        if (index < 0) {
            return "0";
        }

        while(index >= 0) {
            result += to_string(result_integer[index--]);
        }

        return result.empty() ? "0" : result;
    }
};

int main()
{
    Solution sol;
    cout << sol.multiply("0", "0") << endl;
}
