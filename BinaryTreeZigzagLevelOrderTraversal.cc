class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > results;
            vector<int> levelresult;
            if(!root)
                return results;
            queue<TreeNode*> myqueue;
            map<TreeNode*, int> levelmapping;
            levelmapping.insert(make_pair(root, 0));
            myqueue.push(root);
            int totallevel = 0;
            while(!myqueue.empty()) {
                TreeNode *currentnode = myqueue.front();
                myqueue.pop();
                int currentlevel = levelmapping.find(currentnode)->second;
                if(currentlevel > totallevel)
                    totallevel = currentlevel;
                if(currentlevel > results.size()) {
                    if(!(currentlevel%2))
                        reverse(levelresult.begin(), levelresult.end());
                    results.push_back(levelresult);
                    levelresult.clear();
                    levelresult.push_back(currentnode->val);
                } else {
                    levelresult.push_back(currentnode->val);
                }
                if(currentnode->left) {
                    levelmapping.insert(make_pair(currentnode->left, currentlevel+1));
                    myqueue.push(currentnode->left);
                }
                if(currentnode->right) {
                    levelmapping.insert(make_pair(currentnode->right, currentlevel+1));
                    myqueue.push(currentnode->right);
                }
            }
            if(totallevel%2)
                reverse(levelresult.begin(), levelresult.end());
            results.push_back(levelresult);
            return results;
        }
};
