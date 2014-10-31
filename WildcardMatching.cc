class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            const char *star = NULL;
            const char *s_covered_by_star = NULL;
            while(*s) {
                if(*s == *p || *p == '?') {
                    s++; p++; continue;
                } else if (*p == '*') {
                    star = p;
                    s_covered_by_star = s;
                    p++;
                } else if (star) {
                    p = star + 1;
                    s_covered_by_star++;
                    s = s_covered_by_star;
                } else {
                    return false;
                }
            }
            while(*p == '*') {
                p++;
            }
            return !(*p);
        }
};
