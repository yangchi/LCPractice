class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            sort(num.begin(), num.end());
            vector<vector<int>> result;
            int left, right;
            for (int fixed = 0; fixed < num.size(); fixed++) {
                if (fixed > 0 && num[fixed] == num[fixed - 1]) {
                    continue;
                }
                left = fixed + 1;
                right = num.size() - 1;
                while(left < right) {
                    int cur_sum = num[fixed] + num[left] + num[right];
                    if (cur_sum == 0) {
                        vector<int> current = {num[fixed], num[left], num[right]};
                        result.push_back(current);
                        do {
                            left++;
                        } while(num[left] == num[left - 1] && left < right);
                        do {
                            right--;
                        } while(num[right] == num[right + 1] && left < right);
                    } else if (cur_sum < 0) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }

            return result;
        }
};
