#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string result;
            int count = 0;
            while(count++ < n) {
                if (result.empty()) {
                    result = "1";
                    cout << "current iteration: " << result << endl;
                }
                else {
                    char current = result[0];
                    int char_counter = 1;
                    int index = 1;
                    string temp;
                    while (index < result.size()) {
                        if (result[index] == current) {
                            char_counter++;
                            index++;
                        } else {
                            temp += to_string(char_counter) + current;
                            current = result[index];
                            char_counter = 1;
                            index++;
                        }
                    }
                    temp += to_string(char_counter) + current;
                    result = temp;
                    cout << "current iteration: " << result << endl;
                }
            }
            return result;
        }
};

int main()
{
    Solution sol;
    cout << sol.countAndSay(4) << endl;
}
