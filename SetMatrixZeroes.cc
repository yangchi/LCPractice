class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return;
        set<int> rows_to_clear, cols_to_clear;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows_to_clear.insert(i);
                    cols_to_clear.insert(j);
                }
            }
        }
        for(auto row: rows_to_clear)
        {
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[row][j] = 0;
        }
        for(auto col: cols_to_clear)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][col] = 0;
    }
};