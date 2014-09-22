class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(start == end)
                return 1;
            if(dict.find(end) == dict.end())
                dict.insert(end);
            map<string, int> distance_sofar;
            queue<string> tovisit;
            tovisit.push(start);
            distance_sofar[start] = 0;
            while(!tovisit.empty())
            {
                string current = tovisit.front();
                tovisit.pop();
                for(int i = 0; i < current.size(); i++)
                {
                    string next = current;
                    for(int j = 0; j < 26; j++)
                    {
                        if('a' + j == current[i])
                            continue;
                        next[i] = 'a' + j;
                        if(dict.find(next) != dict.end())
                        {
                            if(next == end)
                                return distance_sofar[current]+2;
                            else
                            {
                                if(distance_sofar.find(next) != distance_sofar.end())
                                    distance_sofar[next] = distance_sofar[next] < (distance_sofar[current]+1) ? distance_sofar[next] : (distance_sofar[current]+1);
                                else
                                {
                                    tovisit.push(next);
                                    distance_sofar[next] = distance_sofar[current]+1;
                                }
                            }
                        }
                    }
                }

            }
            return 0;
        }
};
