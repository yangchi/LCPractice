class Solution {
    public:
        string getPermutation(int n, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> facs(n, 1); //factorials: 0, 1!, ..., (n-1)!
            for(int i = 1; i < facs.size(); i++){
                facs[i] *= facs[i-1] * i;
            }
            k--;
            string output;
            vector<int> num_each_fac(n, 0);
            for(int i = n; i > 0; i--){
                if(k >= facs[i-1]){
                    num_each_fac[i-1] = k/facs[i-1];
                    k = k % facs[i-1];
                }
            }
            vector<int> digs(n);
            for(int i = 0; i < n; i++)
                digs[i] = i+1;
            for(int i = n; i > 0; i--){
                output.append(to_string(digs[num_each_fac[i-1]]));
                digs.erase(digs.begin()+num_each_fac[i-1]);
            }
            return output;
        }
};
