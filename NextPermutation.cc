class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int pos = change_point(num);
            if(pos != -1){
                swap(num, pos, change_destination(num, pos));
                sort(num.begin()+pos+1, num.end());
            } else {
                sort(num.begin(), num.end());
            }

        }
        int change_point(const vector<int> & vec){
            for(int i = vec.size(); i >0 ; i--)
                if(vec[i-2] < vec[i-1])
                    return i-2;
            return -1;
        }

        int change_destination(const vector<int> & vec, int change_pos){
            for(int i = vec.size(); i > change_pos; i--){
                if(vec[i-1] > vec[change_pos])
                    return i-1;
            }
        }

        void swap(vector<int> & vec, int p, int q){
            int temp = vec[p];
            vec[p] = vec[q];
            vec[q] = temp;
        }

};
