class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            map<int, int> value_index;
            for(int i = 0; i < numbers.size(); i++) {
                value_index[numbers[i]] = i;
            }

            for(int i = 0; i < numbers.size(); i++) {
                if (value_index.find(target - numbers[i]) != value_index.end() && value_index[target - numbers[i]] != i) {
                    vector<int> result;
                    result.push_back(i + 1);
                    result.push_back(value_index[target - numbers[i]] + 1);
                    return result;
                }
            }

            return vector<int>();
        }
};
