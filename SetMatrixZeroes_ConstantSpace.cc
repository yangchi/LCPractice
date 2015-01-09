class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return;
            }

            bool first_row_has_zero = false, first_col_has_zero = false;
            int rows = matrix.size();
            int cols = matrix[0].size();
            for(int i = 0; i < cols; i++) {
                if (matrix[0][i] == 0) {
                    first_row_has_zero = true;
                    break;
                }
            }

            for(int i = 0; i < rows; i++) {
                if (matrix[i][0] == 0) {
                    first_col_has_zero = true;
                    break;
                }
            }

            for(int i = 1; i < rows; i++) {
                for(int j = 1; j < cols; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }

            for(int i = 1; i < cols; i++) {
                if (matrix[0][i] == 0) {
                    for(int j = 1; j < rows; j++) {
                        matrix[j][i] = 0;
                    }
                }
            }

            for(int j = 1; j < rows; j++) {
                if (matrix[j][0] == 0) {
                    for (int i = 1; i < cols; i++) {
                        matrix[j][i] = 0;
                    }
                }
            }

            if (first_row_has_zero) {
                for(int i = 1; i < cols; i++) {
                    matrix[0][i] = 0;
                }
            }

            if (first_col_has_zero) {
                for (int i = 1; i < rows; i++) {
                    matrix[i][0] = 0;
                }
            }

            if (first_col_has_zero || first_row_has_zero) {
                matrix[0][0] = 0;
            }

            return;
        }
};
