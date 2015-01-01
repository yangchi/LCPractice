class Solution {
public:
    int majorityElement(vector<int> &num) {
        vector<int>::iterator candidate = num.end();
        int counter = 0;
        for(auto iter = num.begin(); iter != num.end(); iter++) {
            if(counter == 0) {
                candidate = iter;
                counter++;
            } else if (*candidate != *iter) {
                if (--counter == 0) {
                    candidate = iter;
                }
            } else {
                counter++;
            }
        }
        return *candidate;
    }
};
