class Solution {
    public:
        string addBinary(string a, string b) {
            if (a.empty()) {
                return b;
            }

            if (b.empty()) {
                return a;
            }

            int carryover = 0;
            string result = "";
            int index = 0;
            int smaller_size = min(a.size(), b.size());
            while(index < smaller_size) {
                int a_bit = a[a.size() - index - 1] - '0';
                int b_bit = b[b.size() - index - 1] - '0';
                int result_bit = (a_bit + b_bit + carryover) & 1;
                carryover = ((a_bit + b_bit + carryover) >> 1) & 1;
                result = to_string(result_bit) + result;
                index++;
            }

            while (index < a.size()) {
                int a_bit = a[a.size() - index - 1] - '0';
                int result_bit = (a_bit + carryover) & 1;
                carryover = ((a_bit + carryover) >> 1) & 1;
                result = to_string(result_bit) + result;
                index++;
            }

            while (index < b.size()) {
                int b_bit = b[b.size() - index - 1] - '0';
                int result_bit = (b_bit + carryover) & 1;
                carryover = ((b_bit + carryover) >> 1) & 1;
                result = to_string(result_bit) + result;
                index++;
            }

            if(carryover) {
                result = "1" + result;
            }

            return result;
        }
};
