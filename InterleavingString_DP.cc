#include <iostream>

using namespace std;


class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if(s1.length() + s2.length() != s3.length()) {
                return false;
            }
            bool interleave[s1.length() + 1][s2.length() + 1];
            for(int i = 0; i < s1.length() + 1; i++)
                for(int j = 0; j < s2.length() + 1; j++)
                    interleave[i][j] = false;
            interleave[0][0] = true;
            int ind1 = 0, ind2 = 0, ind3 = 0;
            for(ind1 = 0; ind1 < s1.length() + 1; ind1++) {
                for(ind2 = 0; ind2 < s2.length() + 1; ind2++) {
                    if(s1[ind1] == s3[ind1 + ind2]) {
                        interleave[ind1 + 1][ind2] = interleave[ind1 + 1][ind2] || interleave[ind1][ind2];
                    }
                    if(s2[ind2] == s3[ind1 + ind2]) {
                        interleave[ind1][ind2 + 1] = interleave[ind1][ind2 + 1] || interleave[ind1][ind2];
                    }
                }
            }
            return interleave[s1.length()][s2.length()];
        }
};

int main() {
    Solution sol;
    cout << "Answer: " << sol.isInterleave("aabaac", "aadaaeaaf", "aadaaeaabaafaac") << endl;

}


