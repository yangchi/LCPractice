class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> result;
            int number = 0;
            int counter = 0;
            result.push_back(number);
            while(counter < n) {
                for (int i = result.size() - 1; i >= 0; i--) {
                    int new_elem = result[i] ^ (1 << counter);
                    result.push_back(new_elem);
                }
                counter++;
            }

            return result;
        }
};
