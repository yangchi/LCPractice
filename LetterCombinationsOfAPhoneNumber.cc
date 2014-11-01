#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string> result;
        letterCombinationsRecur(temp, 0, digits, result);
        return result;
    }
    
    void letterCombinationsRecur(string current, int current_position, string digits, vector<string> & result) {
        if(current_position == digits.size()) {
            result.push_back(current);
            return;
        }
        char curr_char = digits[current_position];
        for(auto letter : letterToVecChar(curr_char)) {
            string newcurrent = current + letter;
            letterCombinationsRecur(newcurrent, current_position + 1, digits, result);
        }
        return;
    }
    
    vector<char> letterToVecChar(char c) {
        switch(c) {
            case '2':
                return vector<char>({'a', 'b', 'c'});
            case '3':
                return vector<char>({'d', 'e', 'f'});
            case '4':
                return vector<char>({'g', 'h', 'i'});
            case '5':
                return vector<char>({'j', 'k', 'l'});
            case '6':
                return vector<char>({'m', 'n', 'o'});
            case '7':
                return vector<char>({'p', 'q', 'r', 's'});
            case '8':
                return vector<char>({'t', 'u', 'v'});
            case '9':
                return vector<char>({'w', 'x', 'y', 'z'});
            default:
                return vector<char>();
        }
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.letterCombinations("23");
    for(auto elem: result)
        cout << elem << endl;
}
