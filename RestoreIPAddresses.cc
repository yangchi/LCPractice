class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        splitter(s, 4, result);
        return result;
    }    

    bool splitter(string s, int limit, vector<string> & result) {
        if(!limit || limit > 0 && s.empty())
            return false;
        int number;
        if(limit == 1) {
            if(s[0] == '0' && s.size() > 1)
                return false;
            number = atoi(s.c_str());
            if(number <= 255) {
                vector<string>::iterator iter;
                for(iter = result.begin(); iter != result.end(); iter++)
                    *iter += s;
                return true;
            }
            else
                return false;
        }
        bool workable = false;
        vector<string> results;
        for(int i = 1; i <=3 && i <= s.size(); i++) {
            if(s[0] == '0' && i > 1)
                continue;
            vector<string> newresult(result);
            number = atoi(s.substr(0, i).c_str());
            if(number <= 255) {
                if(limit == 4) {
                    newresult.push_back(s.substr(0, i)+'.');
                } else {
                    vector<string>::iterator iter;
                    for(iter = newresult.begin(); iter != newresult.end(); iter++) {
                        *iter += s.substr(0, i) + ".";
                    }
                }
                if(splitter(s.substr(i), limit-1, newresult)) {
                    workable = true;
                    copy(newresult.begin(), newresult.end(), back_inserter(results));
                }
            }
        }
        if(workable) {
            result = results;
            return true;
        }
        else {
            return false;
        }
    }
};
