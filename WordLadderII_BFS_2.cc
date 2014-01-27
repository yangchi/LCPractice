//MLE
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> results;
        vector<string> path;
        deque<vector<string>> paths_sofar;
        dict.insert(start);
        dict.insert(end);
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
                for(int i = 0; i < leaf.size(); i++)
                {
                    char oldchar = leaf[i];
                    for(char c = 'a'; c < 'z'; c++)
                    {
                        if(leaf[i] != c)
                            leaf[i] = c;
                        if(find(cur_path.begin(), cur_path.end(), leaf) == cur_path.end())
                        {
                            vector<string> newpath{cur_path};
                            newpath.push_back(leaf);
                            paths_sofar.push_back(newpath);
                        }
                    }
                    leaf[i] = oldchar;
                }
            }
        }
        return results;
    }
    
    
    
};


