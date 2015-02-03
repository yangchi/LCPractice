#include <numeric>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if (nRows == 1) {
                return s;
            }
            vector<string> str_vec(nRows, string());
            int modulo = nRows * 2 - 2;
            for (int i = 0; i < s.size(); i++) {
                int index = i % modulo;
                if (index > modulo / 2) {
                    index = modulo - index;
                }
                str_vec[index] += s[i];
            }

            string result = accumulate(str_vec.begin(), str_vec.end(), string());
            return result;
        }
};


int main()
{
    Solution sol;
    cout << sol.convert("abcde", 3) << endl;
}
