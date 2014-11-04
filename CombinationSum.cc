class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int>> result;
            vector<int> current;
            sort(candidates.begin(), candidates.end());
            combinationSumRecur(candidates, 0, target, current, result);
            return result;
        }



        void combinationSumRecur(vector<int> & candidates, int index, int target, vector<int> & current, vector<vector<int>> & result)  {
            if(target == 0) {
                result.push_back(current);
                return;
            }

            for(int i = index; i < candidates.size(); i++) {
                if(candidates[i] <= target) {
                    current.push_back(candidates[i]);
                    combinationSumRecur(candidates, i, target - candidates[i], current, result);
                    current.pop_back();
                } 
            }
        }
};
