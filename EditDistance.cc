#include <iostream>
#include <string>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        if (word1.empty() && word2.empty())
            return 0;
        if (word1.empty())
            return word2.length();
        if (word2.empty())
            return word1.length();
        int score[word1.length() + 1][word2.length() + 1];
        for(int i = 0; i < word1.length() + 1; i++) {
            score[i][0] = i;
        }
        for(int i = 0; i < word2.length() + 1; i++) {
            score[0][i] = i;
        }
        for(int i = 0; i < word1.length(); i++) {
            for(int j = 0; j < word2.length(); j++) {
                if(word1[i] == word2[j]) {
                    score[i + 1][j + 1] == score[i][j];
                } else {
                    int replace_s = score[i][j] + 1;
                    int remove_s = score[i][j + 1] + 1;
                    int delete_s = score[i + 1][j] + 1;
                    score[i + 1][j + 1] = min(replace_s, remove_s);
                    score[i + 1][j + 1] = min(delete_s, score[i + 1][j + 1]);
                }
            }
        }
        return score[word1.length()][word2.length()];
    }
};


int main()
{
    Solution sol;
    std::cout << sol.minDistance("a", "a") << std::endl;
}
