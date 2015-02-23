class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            int64_t num = numerator;
            int64_t den = denominator;
            string sign = (num > 0 && den < 0 || num < 0 && den > 0) ? "-" : "";
            if (num < 0) {
                num = -num;
            }

            if (den < 0) {
                den = -den;
            }
            if (den == 1) {
                return sign + to_string(num);
            }
            string integer_part = to_string(num / den);
            num = num - den * (num / den);
            if (num == 0) {
                return sign + integer_part;
            }

            map<int64_t, int> rem_index; //map rem to index
            string frac_part = ".";
            rem_index[num] = frac_part.size();
            num *= 10;
            while(num > 0) {
                while (num < den) {
                    frac_part += "0";
                    rem_index[num] = frac_part.size();
                    num *= 10;
                }
                int64_t rem = num - den * (num / den);
                frac_part += to_string(num / den);
                if (rem_index.find(rem) != rem_index.end()) {
                    frac_part = frac_part.substr(0, rem_index[rem]) + "(" + frac_part.substr(rem_index[rem]) + ")";
                    break;
                } else {
                    rem_index[rem] = frac_part.size();
                    num = rem * 10;
                }
            }

            return sign + integer_part + frac_part;
        }
};
