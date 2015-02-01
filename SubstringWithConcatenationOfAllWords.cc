class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int str_len = L[0].size();
        if (S.size() < str_len) {
            return vector<int>();
        }

        map<string, int> needs;
        for(auto & l : L) {
            needs[l]++;
        }
        vector<int> result;
        map<string, int> has;
        int begin = -1;
        int counter = 0;
        int index = 0;
        while(index < S.size()) {
            string current = S.substr(index, str_len);
            if(needs.find(current) == needs.end()) {
                counter = 0;
                has.clear();
                if (begin == -1) {
                    index++;
                } else {
                    index = begin + 1;
                    begin = -1;
                }
            } else {
                if (begin == -1) {
                    begin = index;
                }
                if (has[current] == needs[current]) {
                    index = begin + 1;
                    begin = -1;
                    has.clear();
                    counter = 0;
                } else {
                    counter++;
                    if(counter == L.size()) {
                        result.push_back(begin);
                        has.clear();
                        counter = 0;
                        index = begin + 1;
                        begin = -1;
                    } else {
                        has[current]++;
                        index += str_len;
                    }
                }
            }
        }
        return result;
    }
};
