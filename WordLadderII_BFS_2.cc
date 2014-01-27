class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, unordered_set<string>> nexthops;
        vector<vector<string>> results;
        vector<string> path;
        deque<vector<string>> paths_sofar;
        dict.insert(start);
        dict.insert(end);
        build_next_hops(nexthops, dict);
        int min = dict.size();
        path.push_back(start);
        paths_sofar.push_back(path);
        while(!paths_sofar.empty())
        {
            vector<string> cur_path = paths_sofar.front();
            if(cur_path.size() > min)
                break;
            paths_sofar.pop_front();
            string leaf = cur_path.back();
            if(leaf == end)
            {
                if(cur_path.size() < min)
                {
                    min = cur_path.size();
                    results.clear();
                    results.push_back(cur_path);
                }
                else if(cur_path.size() == min)
                {
                    results.push_back(cur_path);
                }
            }
            else
            {
                if(cur_path.size() > min-1)
                    continue;
                unordered_set<string> nhs = nexthops.find(leaf)->second;
                for(auto word: nhs)
                {
                    if(find(cur_path.begin(), cur_path.end(), word) == cur_path.end())
                    {
                        vector<string> newpath{cur_path};
                        newpath.push_back(word);
                        paths_sofar.push_back(newpath);
                    }
                }
            }
        }
        return results;
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

