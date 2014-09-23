class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            map<int, bool> used;
            vector<int>::const_iterator iter;
            for(iter = num.begin(); iter != num.end(); iter++){
                used.insert(make_pair(*iter, false));
            }
            vector<int> temp;
            vector<vector<int> > result;
            permutation(0, used, num, temp, result);
            return result;
        }

        void permutation(int position, map<int, bool> & used, vector<int> & num, vector<int> & current, vector<vector<int> > & result){
            if(position == num.size()){
                result.push_back(current);
                //current.clear();
                return;
            }
            vector<int>::const_iterator iter;
            for(iter = num.begin(); iter != num.end(); iter++){
                if(!used.find(*iter)->second){
                    current.push_back(*iter);
                    used.find(*iter)->second = true;
                    permutation(position+1, used, num, current, result);
                    used.find(*iter)->second = false;
                    current.pop_back();
                }
            }
        }
};
