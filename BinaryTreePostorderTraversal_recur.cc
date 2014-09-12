#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        std::vector<int> postorderTraversal(TreeNode *root) {
            std::vector<int> vec;
            if(!root) {
                return vec;
            }
            std::vector<int> left = postorderTraversal(root->left);
            std::vector<int> right = postorderTraversal(root->right);
            vec.insert(vec.end(), left.begin(), left.end());
            vec.insert(vec.end(), right.begin(), right.end());
            vec.push_back(root->val);
            return vec;
        }
};

int main() {
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(2);
    first->left = second;
    Solution mysolution;
    std::vector<int> vec = mysolution.postorderTraversal(first);
    std::cout << vec.size() << std::endl;
    std::vector<int>::iterator iter;
    for(iter = vec.begin(); iter != vec.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}
