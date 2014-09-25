class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode*> nodestack;
        vector<int> result;
        TreeNode *current;
        if(!root)
            return result;
        if(root->left)
        {
            current = root;
            while(current->left)
            {
                nodestack.push(current);
                current = current->left;
            }
            nodestack.push(current);
        }
        else
        {
            nodestack.push(root);
        }
        while(!nodestack.empty())
        {
            current = nodestack.top();
            if(current->right)
            {
                result.push_back(current->val);
                nodestack.pop();
                current = current->right;
                if(current->left)
                {
                    while(current->left)
                    {
                        nodestack.push(current);
                        current = current->left;
                    }
                    nodestack.push(current);
                }
                else
                {
                    nodestack.push(current);
                }
            }
            else
            {
                result.push_back(current->val);
                nodestack.pop();
            }
        }
        return result;
    }
};