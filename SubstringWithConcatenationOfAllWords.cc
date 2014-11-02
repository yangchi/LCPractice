#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if(L.empty()) {
            return vector<int>();
        }
        int str_length = L[0].size();
        if(S.size() < str_length)
            return vector<int>();
        if(S.size() == str_length) {
            if(L.size() > 1) {
                return vector<int>();
            } else if(L[0] != S) {
                return vector<int>();
            } else {
                return vector<int>({0});
            }
        }
        map<string, int> str_need;
        for(auto str : L) {
            if(str_need.find(str) == str_need.end()) {
                str_need.insert(make_pair(str, 1));
            } else {
                str_need[str]++;
            }
        }
        map<string, int> still_need(str_need); 
        vector<int> result;
        int index = 0;
        for(int i = 0; i < S.size() - str_length; ) {
            string curr = S.substr(i, str_length);
            cout << "Cuurrent i and substr: " << i << " " << curr << endl;
            if(str_need.find(curr) != str_need.end()) { // in the set
                cout << "\tin the set" << endl;
                if(still_need[curr] > 0) { // need it
                    still_need[curr]--;
                    if(still_need[curr] == 0) {
                        still_need.erase(curr);
                        if(still_need.empty()) {
                            result.push_back(index);
                            i = ++index;
                            still_need = str_need;
                        }
                    } else { //still has needs
                        i += str_length;
                    }
                } else { //more than needed
                    still_need = str_need;
                    i = ++index;
                }
            } else { // not in the set, backtrace to index + 1
                cout << "\t not in the set" << endl;
                still_need = str_need; //reset still_need map
                i = ++index;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> input({"aa", "aa"});
    vector<int> result = sol.findSubstring("aaa", input);
    for(auto elem: result) {
        cout << elem << endl;
    }
}
