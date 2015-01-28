#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current = "";
        splitToSections(s, 4, result, current);
        return result;
    }

    bool legitStr(string s) {
        if (s.empty()) {
            return false;
        }

        if (s.size() > 1 && s[0] == '0' && s[1] == '0') {
            return false;
        }

        int num = stoi(s);
        if (s[0] == '0' && num > 0) {
            return false;
        }
        return num >= 0 && num <= 255;
    }

    void splitToSections(string s, int num_sections, vector<string> & result, string current) {
        if (s.size() < num_sections || s.size() > 3 * num_sections) {
            return;
        }
        if (num_sections == 1) {
            if (legitStr(s)) {
                current += "." + s;
                result.push_back(current);
            } else {
                return;
            }
        }

        for (int i = 1; i <= min((int)s.size() - 1, 3); i++) {
            string substr = s.substr(0, i);
            if (legitStr(substr)) {
                string new_current = "";
                if (current.empty()) {
                    new_current = substr;
                } else {
                    new_current = current + "." + substr;
                }
                string new_s = s.substr(i);
                splitToSections(new_s, num_sections - 1, result, new_current);
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.restoreIpAddresses("255255255255");
    for(auto ip : result) {
        cout << "Legit IP: " << ip << endl;
    }

}
