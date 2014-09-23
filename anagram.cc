class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            map<string, vector<string> > mappings;
            for(auto str: strs)
            {
                string temp(str);
                sort(temp.begin(), temp.end());
                mappings[temp].push_back(str);
            }
            vector<string> result;
            for(auto mapping: mappings)
            {
                if(mapping.second.size() > 1)
                {
                    copy(mapping.second.begin(), mapping.second.end(), back_inserter(result));
                }
            }
            return result;
        }
};
