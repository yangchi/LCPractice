class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> ways(s.size(), 0);
        for(int i = s.size() - 1; i >= 0; i--) {
            if (i == s.size() - 1) {
                if(decodable(s[i])) {
                    ways[i] = 1;
                }
            } else if (i == s.size() - 2){
                if (decodable(s[i])) {
                    ways[i] += ways[i + 1];
                }
                string substr = s.substr(i, 2);
                if (decodable(substr)) {
                    ways[i]++;
                }
            } else {
                if (decodable(s[i])) {
                    ways[i] += ways[i + 1];
                }
                if (i < s.size() - 2) {
                    string substr = s.substr(i, 2);
                    if (decodable(substr)) {
                        ways[i] += ways[i + 2];
                    }
                }
            }
        }

        return ways[0];
    }

    bool decodable(char c) {
        return c != '0';
    }

    bool decodable(string s) {
        if (s[0] != '1' && s[0] != '2') {
            return false;
        }

        int num = stoi(s);
        return num <= 26 && num >= 10;
    }
};
