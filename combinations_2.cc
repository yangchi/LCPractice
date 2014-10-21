#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int>> result;
            vector<int> vec;
            combination(n, k, 1, vec, result);
            return result;
        }

        void combination(int n, int k, int current, vector<int> & vec, vector<vector<int>> & result) {
            if (k == 0) {
                result.push_back(vec);
                return;
            }

            for(int i = current; i <= n; i++) {
                vec.push_back(i);
                combination(n, k - 1, i + 1, vec, result);
                vec.pop_back();
            }
        }

};

int main() {
    Solution sol;
    vector<vector<int>> result = sol.combine(4, 2);
    cout << "size: " << result.size() << endl;
    for(auto vec: result) {
        for(auto elem: vec) {
            cout << elem << " ";
        }
        cout << endl;
    }
}
