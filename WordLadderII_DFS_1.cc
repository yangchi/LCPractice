//TLE
class Solution {
    public:

        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<string> > result;
            vector<string> path;
            map<string, unordered_set<string> > next_hops;
            build_next_hops(next_hops, dict);
            recursiveVisit(start, end, path, result, dict, next_hops);
            if(result.empty())
                return result;
            int min = result[0].size(); 
            for(auto vec: result)
            {
                if(vec.size() < min)
                    min = vec.size();
            }
            vector<vector<string> > refined;
            for(auto vec: result)
                if(vec.size() == min)
                    refined.push_back(vec);
            return refined;
        }

        void recursiveVisit(string current, string end, vector<string> & path, vector<vector<string> > & result, const unordered_set<string> & dict, const map<string, unordered_set<string> > & next_hops)
        {
            path.push_back(current);
            if(current == end)
            {
                result.push_back(path);
                //path.clear();
                return;
            }

            //unordered_set<string> nexts = next_hops(current, dict);
            unordered_set<string> nexts = next_hops.find(current)->second;
            for(auto item: nexts)
            {
                if(find(path.begin(), path.end(), item) == path.end())
                {
                    vector<string> current_path(path);
                    recursiveVisit(item, end, current_path, result, dict, next_hops);
                }
            }
        }

        int diff(string word1, string word2)
        {
            int count = 0;
            for(int i = 0; i < word1.size(); i++)
                if(word1[i] != word2[i])
                    count++;
            return count;
        }

        /*
           unordered_set<string> next_hops(string word, const unordered_set<string> & dict)
           {
           unordered_set<string> result;
           for(auto item: dict)
           {
           if(diff(word, item) == 1)
           {
           result.insert(item);
           }
           }
           return result;
           }
           */

        void build_next_hops(map<string, unordered_set<string> > & nhmap, const unordered_set<string> & dict)
        {
            for(auto word: dict)
            {
                unordered_set<string> nhs;
                for(auto another: dict)
                {
                    if(diff(word, another) == 1)
                        nhs.insert(another);
                }
                nhmap.insert(make_pair(word, nhs));
            }
        }
};
