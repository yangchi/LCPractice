class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            map<int, int> num_set;
            sort(num.begin(), num.end());
            for(int i = 0; i < num.size(); i++) {
                num_set.insert(make_pair(num[i], i));
            }
            vector<vector<int>> result;

            for(int i = 0; i < num.size(); i++) {
                for(int j = i + 1; j < num.size(); j++) {
                    int target = 0 - num[i] - num[j];
                    if(num_set.find(target) != num_set.end()) {
                        if(num_set[target] > j) {
                            vector<int> newresult; //{num[i], num[j], target};
                            newresult.push_back(num[i]);
                            newresult.push_back(num[j]);
                            newresult.push_back(target);
                            result.push_back(newresult);
                        }
                    }
                }
            }
            result.erase(unique(result.begin(), result.end()), result.end());
            return result;
        }
};
