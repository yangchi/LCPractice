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
