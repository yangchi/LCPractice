class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            set<vector<int>> result;
            vector<int> temp;
            sort(num.begin(), num.end());
            combinationSum2Recur(num, 0, target, temp, result);
            return vector<vector<int>>(result.begin(), result.end());
        }

        void combinationSum2Recur(vector<int> & num, int index, int target, vector<int> & current, set<vector<int>> & result) {
            if (target == 0) {
                result.insert(current);
                return;
            }
            if(target < 0 || index >= num.size())
                return;

            current.push_back(num[index]);
            combinationSum2Recur(num, index + 1, target - num[index], current, result);
            current.pop_back();
            combinationSum2Recur(num, index + 1, target, current, result);
        }
};
