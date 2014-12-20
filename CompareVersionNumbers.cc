#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t left_bound_1 = version1.find_first_not_of(".");
        size_t left_bound_2 = version2.find_first_not_of(".");
        size_t right_bound_1 = version1.find_first_of(".", left_bound_1);
        size_t right_bound_2 = version2.find_first_of(".", left_bound_2);
        while(left_bound_1 != string::npos || left_bound_2 != string::npos) {
            int sub_version1 = 0, sub_version2 = 0;
            if (left_bound_1 != string::npos) {
                if (right_bound_1 != string::npos) {
                    sub_version1 = stoi(version1.substr(left_bound_1, right_bound_1 - left_bound_1));
                } else {
                    sub_version1 = stoi(version1.substr(left_bound_1));
                }
            }

            if (left_bound_2 != string::npos) {
                if (right_bound_2 != string::npos) {
                    sub_version2 = stoi(version2.substr(left_bound_2, right_bound_2 - left_bound_2));
                } else {
                    sub_version2 = stoi(version2.substr(left_bound_2));
                }
            }

            if (sub_version1 < sub_version2) {
                return -1;
            } else if (sub_version1 > sub_version2) {
                return 1;
            } else {
                left_bound_1 = version1.find_first_not_of(".", right_bound_1);
                left_bound_2 = version2.find_first_not_of(".", right_bound_2);
                right_bound_1 = version1.find_first_of(".", left_bound_1);
                right_bound_2 = version2.find_first_of(".", left_bound_2);
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.compareVersion("1.0", "1.1") << endl;
}
