class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int>> result;
            sort(num.begin(), num.end());
            for(int i = 0; i < num.size(); i++) {
                if(i > 0 && num[i] == num[i - 1]) {
                    continue;
                }
                for(int j = i + 1; j < num.size(); j++) {
                    if (j > i + 1 && num[j] == num[j - 1])
                        continue;
                    int newtarget = target - num[i] - num[j];
                    int left = j + 1;
                    int right = num.size() - 1;
                    while(left < right) {
                        if(num[left] + num[right] ==  newtarget) {
                            vector<int> newresult{num[i], num[j], num[left], num[right]};
                            result.push_back(newresult);
                            if(num[left + 1] != num[left]) {
                                left++;
                            } else {
                                while(left < right && num[left+1] == num[left]) {
                                    left++;
                                }
                            }
                            if(num[right - 1] != num[right]) {
                                right--;
                            } else {
                                while(right > left && num[right - 1] == num[right]) {
                                    right--;
                                }
                            }
                        } else if (num[left] + num[right] > newtarget) {
                            right--;
                        } else {
                            left++;
                        }
                    }
                }
            }
            result.erase(unique(result.begin(), result.end()), result.end());
            sort(result.begin(), result.end());
            return result;
        }
};
