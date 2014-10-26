class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        #direction: 0 un-decided, 1 right, 2 down
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        directions = [[0 for j in range(n)] for i in range(m)]
        distances = [[0 for j in range(n)] for i in range(m)]
        distances[m - 1][n - 1] = grid[m - 1][n - 1]
        for i in range(m):
            directions[i][n - 1] = 2
        for i in range(m - 1, 0, -1):
            distances[i - 1][n - 1] = distances[i][n - 1] + grid[i - 1][n - 1]
        for i in range(n):
            directions[m - 1][i] = 1
        for i in range(n - 1, 0, -1):
            distances[m - 1][i - 1] = distances[m - 1][i] + grid[m - 1][i - 1]
        for i in range(m - 1, 0, -1):
            for j in range(n - 1, 0, -1):
                row = i - 1
                col = j - 1
                right = distances[row][col + 1]
                down = distances[row + 1][col]
                if right < down:
                    directions[row][col] = 1
                    distances[row][col] = right + grid[row][col]
                else:
                    directions[row][col] = 2
                    distances[row][col] = down + grid[row][col]
        return distances[0][0]