bool strComboCompare(const string first, const string second) {
    return (first + second) < (second + first);
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> str_vec;
        for(auto elem : num) {
            str_vec.push_back(to_string(elem));
        }

        sort(str_vec.begin(), str_vec.end(), strComboCompare);
        string result;
        for (auto str : str_vec) {
            result = str + result;
        }

        while(result.size() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }
        return result;
    }
};
