#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> result;
            if(n == 0) {
                result.push_back(NULL);
                return result;
            }
            map<pair<int, int>, vector<TreeNode *>> mapper; //map <start, end> pair to TreeNode vector
            return generateTreeRecur(1, n, mapper);
        }

        vector<TreeNode *> generateTreeRecur(int start, int end, map<pair<int, int>, vector<TreeNode *>> & mapper) {
            vector<TreeNode *> result;
            if(start > end) {
                result.push_back(NULL);
                return result;
            }
            if(start == end) {
                TreeNode *root = new TreeNode(start);
                result.push_back(root);
                mapper.insert(make_pair(make_pair(start, end), result));
                return result;
            }
            if (mapper.find(make_pair(start, end)) != mapper.end()) {
                return mapper[make_pair(start, end)];
            }
            for(int i = start; i <= end; i++) {
                vector<TreeNode *> left_forest = generateTreeRecur(start, i - 1, mapper);
                vector<TreeNode *> right_forest = generateTreeRecur(i + 1, end, mapper);
                for(auto left_tree : left_forest) {
                    for(auto right_tree : right_forest) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left_tree;
                        root->right = right_tree;
                        result.push_back(root);
                    }
                }
            }
            mapper.insert(make_pair(make_pair(start, end), result));
            return result;
        }

};

int main() {
    Solution sol;
    vector<TreeNode *> trees = sol.generateTrees(3);
}
