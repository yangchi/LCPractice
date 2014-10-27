#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            if(n == 0)
                return vector<vector<int>>();
            int total = n * n;
            int count = 0;
            int left = 0, right = n - 1, top = 0, bottom = n - 1;
            vector<vector<int>> result;
            for(int i = 0; i < n; i++) {
                vector<int> vec;
                for(int j = 0; j < n; j++) {
                    vec.push_back(0);
                }
                result.push_back(vec);
            }
            int current_direction = 0;
            while(count < total) {
                if(current_direction == 0) {
                    for(int i = left; i <= right; i++) {
                        result[top][i] = ++count;
                    }
                    current_direction = 1;
                    top++;
                } else if(current_direction == 1) {
                    for(int i = top; i <= bottom; i++) {
                        result[i][right] = ++count;
                    }
                    current_direction = 2;
                    right--;
                } else if(current_direction == 2) {
                    for(int i = right; i >= left; i--) {
                        result[bottom][i] = ++count;
                    }
                    current_direction = 3;
                    bottom--;
                } else  {
                    for(int i = bottom; i >= top; i--) {
                        result[i][left] = ++count;
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
    sol.generateMatrix(2);
}
