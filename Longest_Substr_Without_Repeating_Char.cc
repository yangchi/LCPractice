class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, int> mapper; 
            int length = 0;
            int maxlength = 0;
            if(s.empty())
                return length;
            int index = 0;
            while(index < s.size())
            {
                if(mapper.find(s[index]) == mapper.end())
                {
                    mapper[s[index]] = index+1;
                    index++;
                    length++;
                }
                else
                {
                    index = mapper[s[index]];
                    mapper.clear();
                    if(length > maxlength)
                        maxlength = length;
                    length = 0;
                }
            }
            return maxlength > length ? maxlength : length;
        }
};
