class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            set<int> num_set(num.begin(), num.end());
            int longest = 0;
            while (!num_set.empty()) {
                int curr = *num_set.begin();
                num_set.erase(curr);
                int curr_length = left_right_consecutive(num_set, curr);
                if (curr_length > longest) {
                    longest = curr_length;
                }
            }

            return longest;
        }

        int left_right_consecutive(set<int> & numset, int element) {
            int length = 1;
            if (numset.find(element + 1) != numset.end()) {
                numset.erase(element + 1);
                length += left_right_consecutive(numset, element + 1);
            }

            if (numset.find(element - 1) != numset.end()) {
                numset.erase(element - 1);
                length += left_right_consecutive(numset, element - 1);
            }

            return length;
        }
};
