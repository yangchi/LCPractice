/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *current = root;
        while(current) {
            m_stack.push(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        int result = m_stack.top()->val;
        TreeNode *temp = m_stack.top();
        m_stack.pop();
        temp = temp->right;
        while(temp) {
            m_stack.push(temp);
            temp = temp->left;
        }
        return result;
    }

private:
    stack<TreeNode *> m_stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
