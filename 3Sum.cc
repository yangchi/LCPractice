#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> results;
        for(int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = num.size() - 1;
            while(left < right) {
                if (num[left] + num[right] + num[i] == 0) {
                    results.push_back(vector<int>({num[i], num[left], num[right]}));
                    while(left + 1 < right && num[left + 1] == num[left]) {
                        left++;
                    }
                    left++;
                    while(right - 1 > left && num[right - 1] == num[right]) {
                        right--;
                    }
                    right--;
                } else if (num[left] + num[right] + num[i] < 0) {
                    left++;
                } else {
                    right--;
                }

            }
        }
        results.erase(unique(results.begin(), results.end()), results.end());
        return results;
    }
};

int main()
{
    Solution sol;
    vector<int> input {-1, -1, -1, 0, 1, 1};
    vector<vector<int>> result = sol.threeSum(input);
    for(auto vec: result) {
        for(auto elem: vec) {
             cout << elem << endl;
        }
    }
}
