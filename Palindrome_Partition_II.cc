//Pass all
class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return Partition(s, 0, s.length());
    }
    
    int Partition(string s, int start, int end){
        bool Parlindrome[s.length()+1][s.length()+1];
        for(int len = 1; len <= s.length(); len++){
            for(int first = 0; first <= s.length() - len; first++){
                if(len == 1)
                    Parlindrome[first][first+len] = true;
                else if(len == 2)
                    Parlindrome[first][first+len] = s[first] == s[first+len-1];
                else
                    Parlindrome[first][first+len] = Parlindrome[first+1][first+len-1] && (s[first] == s[first+len-1]);
            }
        }
        int cuts[end-start];
        for(int i = 0; i < end-start; i++)
            cuts[i] = end-start-i-1;
        for(int pos = end-1; pos >= start; pos--){
            for(int cutpoint = pos+1; cutpoint <= end; cutpoint++){
                if(Parlindrome[pos][cutpoint])
                    if(cutpoint == end)
                        cuts[pos] = 0;
                    else
                        cuts[pos] = min(1+cuts[cutpoint], cuts[pos]);
            }
        }
        return cuts[start];
    }
};
