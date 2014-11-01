class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if(!p)
                return s == NULL;
            if(!*p)
                return *s == '\0';
            if(*(p+1) != '*') {
                if(*s == *p || *p == '.' && *s != '\0')
                    return isMatch(s+1, p+1);
                else
                    return false;
            }
            if(isMatch(s, p+2))
                return true;
            while(*s == *p || *p == '.' && *s != '\0')
                if(isMatch(++s, p+2))
                    return true;
            return false;
        }
};
