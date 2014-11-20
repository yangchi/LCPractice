class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> result;
        for(int i = 0; i < n; i++) {
            result.push_back(vector<int>(n, 0));
        }
        int direction = 0;
        int current = 0;
        int row = 0, col = 0;
        while(current < n * n) {
            if(direction == 0) {
                while(col < n && result[row][col] == 0) {
                    result[row][col] = ++current;
                    col++;
                }
                row++;
                col--;
                direction = 1;
            } else if(direction == 1) {
                while(row < n && result[row][col] == 0) {
                    result[row][col] = ++current;
                    row++;
                }
                row--;
                col--;
                direction = 2;
            } else if(direction == 2) {
                while(col >= 0 && result[row][col] == 0) {
                    result[row][col] = ++current;
                    col--;
                }
                col++;
                row--;
                direction = 3;
            } else {
                while(row >= 0 && result[row][col] == 0) {
                    result[row][col] = ++current;
                    row--;
                }
                row++;
                col++;
                direction = 0;
            }
        }
        return result;
    }
};
