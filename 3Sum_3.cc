class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            sort(num.begin(), num.end());
            vector<vector<int>> result;
            for(int i = 0; i < num.size(); i++) {
                int index_left = i + 1;
                int index_right = num.size() - 1;
                while(index_left < index_right) {
                    if (num[i] + num[index_left] + num[index_right] == 0) {
                        vector<int> newresult;//{num[i], num[index_left++], num[index_right--]};
                        newresult.push_back(num[i]);
                        newresult.push_back(num[index_left++]);
                        newresult.push_back(num[index_right--]);
                        result.push_back(newresult);
                    } else if (num[i] + num[index_left] + num[index_right] > 0) {
                        index_right--;
                    } else {
                        index_left++;
                    }
                }
            }
            result.erase(unique(result.begin(), result.end()), result.end());
            return result;

