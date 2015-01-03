class Solution {
public:
    int majorityElement(vector<int> &num) {
        int candidate = num[0];
        int vote = 0;
        for(auto elem : num) {
            if (vote == 0) {
                candidate = elem;
                vote = 1;
            } else if (candidate == elem) {
                vote++;
            } else {
                vote--;
            }
        }
        return candidate;
    }
};
