class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, unordered_set<string> > nexthops;
        build_nexthops(nexthops, dict);
        vector<string> path;
        deque<vector<string> > paths_sofar;
        int min = dict.size();
        path.push_back(start);
        paths_sofar.push_back(path);
        vector<vector<string> > result;
        while(!paths_sofar.empty())
        {
            vector<string> current = paths_sofar.front();
            if(current.size() > min)
                break;
            paths_sofar.pop_front();
            string last = current.back();
            if(last == end)
            {
                if(current.size() < min)
                {
                    result.clear();
                    result.push_back(current);
                    min = current.size();
                }
                else if(current.size() == min)
                {
                    result.push_back(current);
                }
            }
            else
            {
                if(current.size() > min-1)
                    continue;
                unordered_set<string> hops = nexthops.find(last)->second;
                for(auto next: hops)
                {
                    if(find(current.begin(), current.end(), next) == current.end())
                    {
                        vector<string> newpath(current);
                        newpath.push_back(next);
                        paths_sofar.push_back(newpath);
                    }
                }
            }
        }
        return result;
    }
    
    int diff(string word1, string word2)
    {
        int count = 0;
        for(int i = 0; i < word1.size(); i++)
        {
            if(word1[i] != word2[i])
                count++;
        }
        return count;
    }
    
    void build_nexthops(map<string, unordered_set<string> > & nexthops, const unordered_set<string> & dict)
    {
        for(auto word: dict)
        {
            unordered_set<string> hops;
            for(auto another: dict)
            {
                if(diff(word, another) == 1)
                {
                    hops.insert(another);
                }
            }
            nexthops.insert(make_pair(word, hops));
        }
    }
    
};
