#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int64_t num64 = numerator;
        int64_t dec64 = denominator;
        string sign = ((num64 < 0 && dec64 > 0) || (num64 > 0 && dec64 < 0)) ? "-" : "";
        num64 = num64 > 0 ? num64 : -num64;
        dec64 = dec64 > 0 ? dec64 : -dec64;
        string integer_part = to_string(num64 / dec64);
        if (num64 > dec64) {
            num64 -= num64 / dec64 * dec64;
        }
        string fractional_part = "";
        vector<int64_t> num_seq({num64});
        num64 *= 10;
        while (num64) {
            if (num64 < dec64) {
                fractional_part += "0";
                num_seq.push_back(num64);
                num64 *= 10;
                continue;
            }

            fractional_part += to_string(num64 / dec64);
            num64 -= num64 / dec64 * dec64;
            if (find(num_seq.begin(), num_seq.end(), num64) != num_seq.end()) { //loop
                size_t loop_point = find(num_seq.begin(), num_seq.end(), num64) - num_seq.begin();
                return sign + integer_part + "." + fractional_part.substr(0, loop_point) + "(" + fractional_part.substr(loop_point) + ")";
            } else {
                num_seq.push_back(num64);
                num64 *= 10;
            }
        }
        return sign + integer_part + (fractional_part.empty() ? "" : "." + fractional_part);
    }
};

int main()
{
    Solution sol;
    cout << sol.fractionToDecimal(-50, 8) << endl;
}
