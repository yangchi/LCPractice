#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void solveSudoku(vector<vector<char> > &board) {
            solveSudokuRecur(board, 0, 0);
        }

        bool solveSudokuRecur(vector<vector<char>> & board, int row, int col) {
            cout << "recur func: " << row << " " << col << endl;
            if(row == 8 && col == 8) {
                if (board[row][col] != '.') {
                    return true;
                }
                for(int candidate = 0; candidate < 9; candidate++) {
                    if(validMove(board, row, col, candidate + 1)) {
                        board[row][col] = candidate + 1 + '0';
                        cout << "Made change at final spot." << endl;
                        return true;
                    }
                }
                return false;
            }

            if(board[row][col] != '.') {
                if(col == 8) {
                    cout << "next row without change. " << endl;
                    return solveSudokuRecur(board, row + 1, 0);
                } else {
                    return solveSudokuRecur(board, row, col + 1);
                }
            } else {
                for(int candidate = 0; candidate < 9; candidate++) {
                    if(validMove(board, row, col, candidate + 1)) {
                        board[row][col] = candidate + 1 + '0';
                        cout << "Made change " << (1 + candidate) << " at  " << row << " " << col << endl;
                        if(col == 8) {
                            cout << "next row after change." << endl;
                            if(solveSudokuRecur(board, row + 1, 0)) {
                                return true;
                            }
                        } else {
                            if(solveSudokuRecur(board, row, col + 1)) {
                                return true;
                            }
                        }
                        board[row][col] = '.';
                        cout << "Revoke change. " << row << " " << col << endl;
                    }
                }
                return false;
            }
        }

        bool validMove(vector<vector<char>> & board, int row, int col, int value) {
            if (board[row][col] != '.') {
                return false;
            }
            for(int i = 0; i < 9; i++) {
                if(board[row][i] - '0' == value || board[i][col] - '0' == value) {
                    cout << board[row][i] << " or " << board[i][col] << " is already the " << value << endl;
                    return false;
                }
            }

            for(int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
                for(int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
                    if(board[i][j] - '0' == value) {
                        cout << board[i][j] << " at " << i << " " << j << " is already " << value << endl;
                        return false;
                    }
                }
            }
            return true;
        }
};

int main()
{
    Solution sol;
    vector<vector<char>> board;
    string board_arr[] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    for(int i = 0; i < 9; i++) {
        board.push_back(vector<char>(board_arr[i].begin(), board_arr[i].end()));
    }
    sol.solveSudoku(board);
    for(auto vec: board) {
        for(auto elem: vec) {
            cout << elem;
        }
        cout << endl;
    }
}
