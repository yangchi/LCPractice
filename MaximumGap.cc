#include <bitset>

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) {
            return 0;
        }
        int minnum = INT_MAX, maxnum = INT_MIN;
        for(auto elem : num) {
            if (elem < minnum) {
                minnum = elem;
            }
            if (elem > maxnum) {
                maxnum = elem;
            }
        }
        vector<int> bucket_mins(num.size() - 1, INT_MAX);
        vector<int> bucket_maxs(num.size() - 1, INT_MIN);

        int bucket_size = (int)ceil((double)(maxnum - minnum) / (double)(num.size() - 1));

        for(auto elem : num) {
            if (elem == minnum || elem == maxnum) {
                continue;
            }
            int bucket_index = (elem - minnum) / bucket_size;
            if (elem < bucket_mins[bucket_index]) {
                bucket_mins[bucket_index] = elem;
            }
            if (elem > bucket_maxs[bucket_index]) {
                bucket_maxs[bucket_index] = elem;
            }
        }
        int previous = minnum;
        int maxgap = INT_MIN;
        for (int i = 0; i < num.size() - 1; i++) {
            if (bucket_mins[i] == INT_MAX) { //nothing in this bucket
                continue;
            }
            int gap_to_prev = bucket_mins[i] - previous;
            int gap_current = bucket_maxs[i] - bucket_mins[i];
            maxgap = gap_to_prev > maxgap ? gap_to_prev : maxgap;
            maxgap = gap_current > maxgap ? gap_current : maxgap;
            previous = bucket_maxs[i];
        }
        maxgap = (maxnum - previous) > maxgap ? (maxnum - previous) : maxgap;
        return maxgap;
    }
};
