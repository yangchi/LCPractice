#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            int current_direction = 0;
            int count = 0;
            vector<int> result;
            if(matrix.empty()) {
                return result;
            }
            int top = 0;
            int bottom = matrix.size() - 1;
            int left = 0;
            int right = matrix[0].size() - 1;
            int total = matrix.size() * matrix[0].size();
            while(count < total) {
                cout << "Current direction : " << current_direction << endl;
                cout << "Current count: " << count << endl;
                cout << "Current boundaries: " << top << " " << right << " " << bottom << " " << left << endl;
                if (current_direction == 0) {
                    for (int i = left; i <= right; i++) {
                        result.push_back(matrix[top][i]);
                        count++;
                    }
                    current_direction = 1;
                    top++;
                } else if (current_direction == 1) {
                    for(int i = top; i <= bottom; i++) {
                        result.push_back(matrix[i][right]);
                        count++;
                    }
                    current_direction = 2;
                    right--;
                } else if (current_direction == 2) {
                    for(int i = right; i >= left ; i--) {
                        result.push_back(matrix[bottom][i]);
                        count++;
                    }
                    current_direction = 3;
                    bottom--;
                } else {
                    for(int i = bottom; i >= top; i--) {
                        result.push_back(matrix[i][left]);
                        count++;
                    }
                    current_direction = 0;
                    left++;
                }
            }
            return result;
        }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>());
    matrix.push_back(vector<int>());
    matrix.push_back(vector<int>());
    matrix[0].push_back(2);
    //matrix[0].push_back(5);
    matrix[1].push_back(8);
    //matrix[1].push_back(4);
    matrix[2].push_back(0);
    //matrix[2].push_back(-1);
    vector<int> result = sol.spiralOrder(matrix);
    for(auto elem: result) {
        cout << "elem: " << elem << endl;
    }
}
