class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        rows = [[] for i in range(9)]
        cols = [[] for i in range(9)]
        squares = [[] for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                else:
                    rows[i].append(board[i][j])
                    cols[j].append(board[i][j])
                    if j < 3 and i < 3:
                        squares[0].append(board[i][j])
                    elif j < 3 and i < 6:
                        squares[1].append(board[i][j])
                    elif j < 3:
                        squares[2].append(board[i][j])
                    elif j < 6 and i < 3:
                        squares[3].append(board[i][j])
                    elif j < 6 and i < 6:
                        squares[4].append(board[i][j])
                    elif j < 6:
                        squares[5].append(board[i][j])
                    elif i < 3:
                        squares[6].append(board[i][j])
                    elif i < 6:
                        squares[7].append(board[i][j])
                    else:
                        squares[8].append(board[i][j])
        for i in range(9):
            rows[i].sort()
            for j in range(1, len(rows[i])):
                if rows[i][j] == rows[i][j-1]:
                    return False
            cols[i].sort()
            for j in range(1, len(cols[i])):
                if cols[i][j] == cols[i][j-1]:
                    return False
            squares[i].sort()
            for j in range(1, len(squares[i])):
                if squares[i][j] == squares[i][j-1]:
                    return False
        return True