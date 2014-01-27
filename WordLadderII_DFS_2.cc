//TLE
class Solution {
    public:
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            map<string, unordered_set<string>> nexthops;
            vector<vector<string>> results;
            vector<string> path;
            dict.insert(start);
            dict.insert(end);
            int min = dict.size();
            build_next_hops(nexthops, dict);
            recurFindLadder(start, end, dict, nexthops, path, results, min);
            return results;
            /*
            vector<vector<string>> refined;
            for(auto result: results)
            {
                if(result.size() == min)
                    refined.push_back(result);
            }
            return refined;
            */
        }

        void recurFindLadder(string start, string end, unordered_set<string> & dict, map<string, unordered_set<string>> & nhmap, vector<string> & path, vector<vector<string>> results, int & min)
        {
            path.push_back(start);
            if(path.size() > min)
                return;
            if(start == end)
            {
                if(path.size() < min)
                {
                    min = path.size();
                    results.clear();
                    results.push_back(path);
                }
                return;
            }
            unordered_set<string> nhs = nhmap.find(start)->second;
            for(auto word: nhs)
            {
                if(find(path.begin(), path.end(), word) == path.end())
                {
                    vector<string> curpath{path};
                    recurFindLadder(word, end, dict, nhmap, path, results, min);
                }
            }
        }

        bool diff1(string str1, string str2)
        {
            if(str1.size() != str2.size())
                return false;
            bool diff = false;
            for(int i = 0; i < str1.size(); i++)
                if(str1[i] != str2[i])
                    if(diff)
                        return false;
                    else
                        diff = true;
            return diff;
        }

        void build_next_hops(map<string, unordered_set<string>> & nexthops, unordered_set<string> & dict)
        {
            for(auto word: dict)
            {
                unordered_set<string> nhs;
                for(auto another: dict)
                {
                    if(diff1(word, another))
                        nhs.insert(another);
                }
                nexthops.insert(make_pair(word, nhs));
            }
        }


};

