class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        set<vector<int>> result;
        for(int first = 0; first < num.size(); first++) {
            if (first > 0 && num[first] == num[first - 1]) {
                continue;
            }
            int second = first + 1, third = num.size() - 1;
            while(second < third) {
                int current_sum = num[first] + num[second] + num[third];
                if (current_sum == 0) {
                    result.insert(vector<int>({num[first], num[second], num[third]}));
                    do {
                        second++;
                    } while (num[second - 1] == num[second]);
                    do {
                        third--;
                    } while (num[third + 1] == num[third]);
                } else if (current_sum > 0) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
