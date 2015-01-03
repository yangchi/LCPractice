class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(2, 1);
        for(int i = 2; i < n; i++) {
            factorials.push_back(factorials[factorials.size() - 1] * i);
        }
        vector<int> num_of_factorials(n, 0);
        int temp = k - 1;
        string result;
        vector<int> digits(n);
        for(int i = 0; i < n; i++) {
            digits[i] = i + 1;
        }
        for(int i = n; i > 0; i--) {
            div_t quot_rem = div(temp, factorials[i - 1]);
            result += to_string(digits[quot_rem.quot]);
            digits.erase(digits.begin() + quot_rem.quot);
            temp = quot_rem.rem;
        }
        return result;
    }
};
