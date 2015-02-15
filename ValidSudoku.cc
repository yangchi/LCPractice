class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<set<char>> rows(9, set<char>());
        vector<set<char>> cols(9, set<char>());
        map<pair<int, int>, set<char>> squares;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current == '.') {
                    continue;
                }
                if (rows[i].find(current) != rows[i].end() || cols[j].find(current) != cols[j].end()) {
                    return false;
                } else {
                    rows[i].insert(current);
                    cols[j].insert(current);
                }

                if (squares[std::pair<int, int>(i / 3, j / 3)].find(current) != squares[std::pair<int, int>(i / 3, j / 3)].end()) {
                    return false;
                } else {
                    squares[std::pair<int, int>(i / 3, j / 3)].insert(current);
                }
            }
        }
        return true;
    }
};
