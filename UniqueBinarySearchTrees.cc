class Solution {
    public:
        int numTrees(int n) {
            vector<int> tree_numbers(n + 1, 0);
            tree_numbers[0] = 1;
            tree_numbers[1] = 1;
            for(int i = 2; i < n + 1; i++) {
                for(int left = 0; left < i; left++) {
                    int right = i - 1 - left;
                    tree_numbers[i] += tree_numbers[left] * tree_numbers[right];
                }
            }
            return tree_numbers[n];
        }
};
