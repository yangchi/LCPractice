class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        pascal_triangle = []
        if numRows == 0:
            return pascal_triangle
        pascal_triangle.append([1])
        for i in range(1, numRows):
            current_row = [1]
            for j in range(1, len(pascal_triangle[i-1])):
                current_row.append(pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j])
            current_row.append(1)
            pascal_triangle.append(current_row)
        return pascal_triangle