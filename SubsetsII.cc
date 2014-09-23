class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > results;
            vector<int> temp;
            results.push_back(temp);
            if(S.empty())
                return results;
            sort(S.begin(), S.end());
            for(auto elem: S)
            {
                int currentsize = results.size();
                for(int i = 0; i < currentsize; i++)
                {
                    vector<int> temp(results[i]);
                    temp.push_back(elem);
                    results.push_back(temp);
                }
            }
            set<vector<int> > resset(results.begin(), results.end());
            results.assign(resset.begin(), resset.end());
            return results;
        }
};
