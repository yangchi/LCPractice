class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            vector<vector<bool>> visited;
            for(int i = 0; i < board.size(); i++) {
                vector<bool> empty_bool_vec(board[0].size(), false);
                visited.push_back(empty_bool_vec);
            }
            for(int row = 0; row < board.size(); row ++) {
                for(int col = 0; col < board[0].size(); col++) {
                    if(existence(board, word, visited, row, col)) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool existence(vector<vector<char>> & board, string word, vector<vector<bool>> & flags, int row, int col) {
            if(word.empty())
                return true;
            if(flags[row][col]) {
                return false;
            }
            if(word.size() == 1 && board[row][col] == word[0])
                return true;

            if(board[row][col] == word[0]) {
                flags[row][col] = true;
                if(row > 0) {
                    if(existence(board, word.substr(1), flags, row - 1, col)) {
                        return true;
                    }
                }
                if (col > 0) {
                    if(existence(board, word.substr(1), flags, row, col - 1)) {
                        return true;
                    }
                }
                if (row < board.size() - 1) {
                    if(existence(board, word.substr(1), flags, row + 1, col)) {
                        return true;
                    }
                }
                if (col < board[0].size() - 1) {
                    if(existence(board, word.substr(1), flags, row, col + 1)) {
                        return true;
                    }
                }
                flags[row][col] = false;
            }

            return false;
        }
};
