#include <iostream>

using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(divisor == 1)
                return dividend;
            if (divisor == -1)
                return -dividend;
            int result = 0;
            if(dividend > 0 && divisor > 0) {
                dividend = -dividend; divisor = -divisor;
            }
            int sign = 1;
            if (dividend > 0) {
                sign = -1;
                dividend = -dividend;
            }
            if(divisor > 0) {
                sign = -1;
                divisor = -divisor;
            }
            int count = 1;
            int temp = divisor;
            while(temp + temp  < temp && temp + temp >= dividend) {
                cout << "temp : " << temp << endl;
                temp <<= 1;
                count <<= 1;
            }
            while(dividend <= divisor && temp) {
                cout << "Divided : " << dividend << " temp " << temp << endl;
                if(dividend <= temp) {
                    dividend -= temp;
                    result += count;
                }
                temp >>= 1;
                count >>= 1;
            }
            return result * sign;
        }
};

int main()
{
    Solution sol;
    cout << sol.divide(-2147483648, 2) << endl;
}
