class Solution {
    public:
        bool isPalindrome(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(s.size() < 2)
                return true;
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            string::const_iterator iter = s.begin(), riter = s.end()-1;
            bool hasalphanum = false;
            while(iter <= riter)
            {
                while(!isAlphanum(*iter) && iter < riter)
                    iter++;
                while(!isAlphanum(*riter) && iter < riter)
                    riter--;
                if(*iter++ != *riter--)
                    return false;
                else
                    hasalphanum = true;
            }
            return hasalphanum;
        }

        bool isAlphanum(char c)
        {
            return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
        }
};
