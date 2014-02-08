class Solution {
    public:
        int numDistinct(string S, string T) {
            if(S.empty() || T.empty())
                return 0;
            vector<int> counter_element(S.size(), 0);
            vector<vector<int> > counter(T.size(), counter_element);
            if(T[T.size()-1] == S[S.size()-1])
                counter[T.size()-1][S.size()-1] = 1;
            for(int i = T.size()-1; i >= 0; i--)
            {
                for(int j = S.size()-2; j >= 0; j--)
                {
                    if(T[i] != S[j]) // not match
                    {
                        counter[i][j] = counter[i][j+1];
                    }
                    else
                    {
                        if(i < T.size()-1)
                            counter[i][j] = counter[i+1][j+1] + counter[i][j+1];
                        else if(i == T.size()-1)
                            counter[i][j] = 1 + counter[i][j+1];
                        else
                            counter[i][j] = counter[i][j+1];
                    }
                }
            }
            return counter[0][0];
        }
};
