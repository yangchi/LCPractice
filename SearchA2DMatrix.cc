class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            if(matrix.empty() || matrix[0].empty())
                return false;
            return binarySearchMatrix(matrix, 0, matrix.size(), target);
        }

        bool binarySearchMatrix(vector<vector<int>> & matrix, int start_row, int end_row, int target) {
            if (start_row >= end_row)
                return false;
            int mid_row = start_row + (end_row - start_row) / 2;
            if (target <= matrix[mid_row][matrix[mid_row].size() - 1] && target >= matrix[mid_row][0])
                return binarySearch(matrix[mid_row], target, 0, matrix[mid_row].size());
            if (target < matrix[mid_row][0])
                return binarySearchMatrix(matrix, start_row, mid_row, target);
            if (target > matrix[mid_row][matrix[mid_row].size() - 1])
                return binarySearchMatrix(matrix, mid_row + 1, end_row, target);
        }

        bool binarySearch(vector<int> & vec, int target, int begin, int end) {
            if(begin >= end)
                return false;
            int mid = begin + (end - begin) / 2;
            if (target == vec[mid])
                return true;
            if (target > vec[mid])
                return binarySearch(vec, target, mid + 1, end);
            if (target < vec[mid])
                return binarySearch(vec, target, begin, mid);
        }
};
