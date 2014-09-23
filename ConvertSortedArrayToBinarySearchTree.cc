class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(num.empty())
                return NULL;
            if(num.size() == 1){
                TreeNode * root = new TreeNode(num[0]);
                return root;
            }
            TreeNode * root = new TreeNode(num[num.size()/2]);
            vector<int> firsthalf(num.begin(), num.begin()+num.size()/2);
            vector<int> secondhalf(num.begin()+num.size()/2+1, num.end());
            root->left = sortedArrayToBST(firsthalf);
            root->right = sortedArrayToBST(secondhalf);
            return root;
        }
};
