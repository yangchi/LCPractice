class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            set<int> num_set(num.begin(), num.end());
            int maxcluster = 0;
            for(auto number: num_set)
                maxcluster = max(maxcluster, updown(num_set, number));
            return maxcluster;
        }

        int updown(set<int> & numset, int number)
        {
            int count = 0;
            if(numset.find(number) != numset.end())
            {
                numset.erase(number);
                count++;
                int up = updowncount(numset, number+1, true);
                int down = updowncount(numset, number-1, false);
                count += up + down;
            }
            return count;
        }

        int updowncount(set<int> & numset, int number, bool up)
        {
            int count = 0;
            while(numset.find(number) != numset.end())
            {
                count++;
                numset.erase(number);
                if(up)
                    number++;
                else
                    number--;
            }
            return count;
        }
};

