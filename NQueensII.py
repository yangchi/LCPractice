class Solution:
    # @return an integer
    def totalNQueens(self, n):
        cols = []
        result = []
        self.solveNQueensRecur(n, 0, cols, result)
        return len(result)
    
    def solveNQueensRecur(self, n, row, cols, result):
        if row == n:
            current_row_list = []
            for i in range(n):
                current_row = ""
                for j in range(n):
                    current_row += '.' if j != cols[i] else 'Q'
                current_row_list.append(current_row)
            result.append(current_row_list)
            return
        for col in range(n):
            if col not in cols \
                and all(map(lambda i : col - cols[i] != row - i, range(len(cols)))) \
                and all(map(lambda i : cols[i] - col != row - i, range(len(cols)))):
                    cols.append(col)
                    self.solveNQueensRecur(n, row + 1, cols, result)
                    cols.pop()