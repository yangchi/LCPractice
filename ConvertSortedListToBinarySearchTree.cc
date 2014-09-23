class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!head)
                return NULL;
            ListNode *current = head;
            while(current->next) {
                current = current->next;
            }
            return BuildBST(head, current);
        }

        TreeNode *BuildBST(ListNode *start, ListNode *end) {
            if(start == NULL || end == NULL)
                return NULL;
            if(start == end) {
                TreeNode *root = new TreeNode(start->val);
                return root;
            }
            int counter = 1;
            ListNode *current = start;
            while(current->next && current != end) {
                current = current->next;
                counter++;
            }
            int middle = counter/2;
            current = start;
            while(--middle) {
                current = current->next;
            }
            TreeNode *lefttree = BuildBST(start, current);
            TreeNode *righttree = NULL;
            if(current->next->next && current != end && current->next != end && current->next->next != end)
                righttree = BuildBST(current->next->next, end);
            else if(current->next != end)
                righttree = BuildBST(end, end);
            TreeNode *root = new TreeNode(current->next->val);
            root->left = lefttree;
            root->right = righttree;
            return root;
        }
};
