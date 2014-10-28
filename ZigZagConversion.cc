#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows) {
            if(nRows == 1 || s.size() <= nRows)
                    return s;
            int base = nRows * 2 - 2;
            vector<vector<char>> char_lists;
            for(int i = 0; i < base; i++) {
                char_lists.push_back(vector<char>());
            }
            for(int i = 0; i < s.size(); i++) {
                int reminder = i % base;
                char_lists[reminder].push_back(s[i]);
            }
            string result = "";
            for(auto elem : char_lists[0]) {
                result += elem;
            }
            for(int i = 1; i < nRows - 1; i++) {
                int first = i % base;
                int second = base - first;
                for(int j = 0; j < char_lists[second].size(); j++) {
                    result += char_lists[first][j];
                    result += char_lists[second][j];
                }
                if(char_lists[first].size() > char_lists[second].size()) {
                    result += char_lists[first][char_lists[first].size() - 1];
                }
            }
            for(auto elem : char_lists[(nRows - 1) % base])
                result += elem;
            return result;
        }
};

int main()
{
    Solution sol;
    string result = sol.convert("ABCD", 3);
    cout << result << endl;
    for(char c : result) {
        cout << (int)c << endl;
    }
}
