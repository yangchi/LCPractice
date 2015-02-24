#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<string> > solveNQueens(int n) {
            vector<int> queenCols; //which column is each queen located in row 0 ... n - 1
            vector<vector<string>> boards;
            solveNQueensRecur(0, n, queenCols, boards);
            return boards;
        }

        void solveNQueensRecur(int current_row, int n, vector<int> & qCols, vector<vector<string>> & board) {
            if (current_row == n) {
                generateBoard(n, qCols, board);
                return;
            }

            for (int col = 0; col < n; col++) {
                if(isValidMove(qCols, current_row, col)) {
                    qCols.push_back(col);
                    solveNQueensRecur(current_row + 1, n, qCols, board);
                    qCols.pop_back();
                } 
            }
        }

        bool isValidMove(const vector<int> & qCols, int row, int col) {
            if (qCols.size() > row) {
                return false;
            }

            for (auto qc : qCols) {
                if (qc == col) {
                    return false;
                }
            }

            for (int i = 0; i < qCols.size(); i++) {
                if (qCols[i] - col == row - i || col - qCols[i] == row - i) {
                    return false;
                }
            }

            return true;
        }

        void generateBoard(int size, const vector<int> & qCols, vector<vector<string>> & boards){
            vector<string> board(size, string(size, '.'));
            for (int row = 0; row < size; row++) {
                board[row][qCols[row]] = 'Q';
            }
            boards.push_back(board);
        }
};
