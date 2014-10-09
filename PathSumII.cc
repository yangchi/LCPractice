/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > results;
            if(!root)
                return results;
            if(root->val == sum && !root->left && !root->right)
            {
                vector<int> elem(1, root->val);
                results.push_back(elem);
                return results;
            }
            if(root->left)
            {
                vector<vector<int> > leftresults = pathSum(root->left, sum - root->val);
                for(auto leftresult: leftresults)
                {
                    if(leftresult.empty())
                        continue;
                    vector<int> newresult(1, root->val);
                    copy(leftresult.begin(), leftresult.end(), back_inserter(newresult));
                    results.push_back(newresult);
                }
            }
            if(root->right)
            {
                vector<vector<int> > rightresults = pathSum(root->right, sum - root->val);
                for(auto rightresult: rightresults)
                {
                    if(rightresult.empty())
                        continue;
                    vector<int> newresult(1, root->val);
                    copy(rightresult.begin(), rightresult.end(), back_inserter(newresult));
                    results.push_back(newresult);
                }
            }
            return results;
        }
};
