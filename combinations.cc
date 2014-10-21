#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            set<set<int>> sets = combination(n, k);
            vector<vector<int>> vecs;
            for(auto eset: sets) {
                vector<int> vec(eset.begin(), eset.end());
                vecs.push_back(vec);
            }
            return vecs;
        }

        set<set<int>> combination(int n, int k) {
            set<set<int>> result;
            if (k == 0)
                return result;
            if (k == 1) {
                for(int i = 1; i <= n; i++) {
                    set<int> newset;
                    newset.insert(i);
                    result.insert(newset);
                }
                return result;
            }
            set<set<int>> vecs = combination(n, k - 1);
            for(auto oldset: vecs) {
                for(int i = 1; i <= n; i++) {
                    if(oldset.find(i) == oldset.end()) {
                        oldset.insert(i);
                        result.insert(oldset);
                        oldset.erase(i);
                    }
                }
            }
            return result;
        }
};

int main() {
    Solution sol;
    vector<vector<int>> result = sol.combine(6, 4);
    cout << "size: " << result.size() << endl;
    for(auto vec: result) {
        for(auto elem: vec) {
            cout << elem << " ";
        }
        cout << endl;
    }
}
