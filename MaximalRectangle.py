class Solution:
    # @param matrix, a list of lists of 1 length string
    # @return an integer
    def maximalRectangle(self, matrix):
        rows = len(matrix)
        if rows == 0:
            return 0
        cols = len(matrix[0])
        if cols == 0:
            return 0
        bottom_matrix = [[0 for i in range(cols)] for j in range(rows)]
        for col in range(cols):
            bottom_matrix[0][col] = int(matrix[0][col])
        for row in range(1, rows):
            for col in range(cols):
                bottom_matrix[row][col] = bottom_matrix[row - 1][col] + 1 if int(matrix[row][col]) == 1 else 0
        maxarea = 0
        for row in range(0, rows):
            stack = []
            index = 0
            while index < cols:
                if len(stack) == 0:
                    stack.append(index)
                    index += 1
                elif bottom_matrix[row][index] >= bottom_matrix[row][stack[-1]]:
                    stack.append(index)
                    index += 1
                else:
                    top = stack[-1]
                    stack.pop()
                    width = index - stack[-1] - 1 if len(stack) > 0 else index
                    area = bottom_matrix[row][top] * width
                    if area > maxarea:
                        maxarea = area
            while len(stack) > 0:
                top = stack.pop()
                width = index - stack[-1] - 1 if len(stack) > 0 else index
                area = bottom_matrix[row][top] * width
                if area > maxarea:
                    maxarea = area
        return maxarea
        
        