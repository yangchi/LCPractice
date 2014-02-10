class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return Partition(s, 0, s.length());
    }
    
    bool IsParlindrome(string s, int start, int end){
        if((end-start) < 2)
            return true;
        for(int i = 0; i < (end-start)/2; i++){
            if(s[start+i] != s[end-i-1])
                return false;
        }
        return true;
    }
    
    vector<vector<string> > Partition(string s, int start, int end){
        vector<vector<string> > parlin_vecs;
        if(start >= end)
            return parlin_vecs;
        vector<string> parlindromes;
        for(int step = 1; step <= end-start; step++){
            if(IsParlindrome(s, start, start+step)){
                parlindromes.push_back(s.substr(start, step));
                if(start+step >= end){
                    parlin_vecs.push_back(parlindromes);
                }
                else{
                    vector<vector<string> > tempvec = Partition(s, start+step, end);
                    vector<vector<string> >::const_iterator iter;
                    for(iter = tempvec.begin(); iter != tempvec.end(); iter++){
                        vector<string> temppar(parlindromes);
                        temppar.insert(temppar.end(), iter->begin(), iter->end());
                        parlin_vecs.push_back(temppar);
                    }
                }
                parlindromes.clear();
            }
        }
        return parlin_vecs;
    }
};