class Solution {
    public:
        string minWindow(string S, string T) {


            map<char, int> need;
            for(auto c: T) {
                if (need.find(c) == need.end()) {
                    need[c] = 1;
                } else {
                    need[c]++;
                }
            }

            int index = 0;
            map<char, int> have;
            int begin = -1;
            int minimum = INT_MAX;
            string minimal_string;
            int count = 0;
            while(index < S.size()) {
                char current = S[index];
                if (need.find(current) == need.end()) {
                    index++;
                    continue;
                }
                if (begin == -1) {
                    begin = index;
                }
                if (have.find(current) == have.end()) {
                    have[current] = 1;
                } else {
                    have[current]++;
                }

                if (have[current] <= need[current]) {
                    count++;
                }

                if (count == T.size()) {
                    while(begin < index && (need.find(S[begin]) == need.end() || have[S[begin]] > need[S[begin]])) {
                        if (have[S[begin]] > 0) {
                            have[S[begin]]--;
                        }
                        begin++;
                    }

                    if (index - begin + 1 < minimum) {
                        minimum = index - begin + 1;
                        minimal_string = S.substr(begin, index - begin + 1);
                    }
                }
                index++;
            }
            return minimal_string;
        }
};
