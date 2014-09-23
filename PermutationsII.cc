/*
 * To understand this, check out the "Next Permutation" problem
 */

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > results;
            sort(num.begin(), num.end());
            results.push_back(num);
            int change_pos = search_for_change_point(num);
            while(change_pos != -1){
                int dest = search_for_destination(num, change_pos);
                swap(num, change_pos, dest);
                reverse(num.begin() + change_pos + 1, num.end());
                results.push_back(num);
                change_pos = search_for_change_point(num);
            }
            return results;
        }

        void swap(vector<int> & vec, int i, int j){
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }

        int search_for_change_point(const vector<int> & vec){
            for(int i = vec.size(); i > 1; i--){
                if(vec[i-2] < vec[i-1])
                    return i-2;
            }
            return -1;
        }

        int search_for_destination(const vector<int> & vec, int change_pos){
            for(int i = vec.size(); i > change_pos; i--){
                if(vec[i-1] > vec[change_pos])
                    return i-1;
            }
        }
};
