import java.util.Stack;

public class SurroundedRegions {

    class Pair{
        int X;
        int Y;
        Pair(int x, int y) {this.X = x; this.Y = y;}
    }

    public void solve(char[][] board) {
        int length = board.length;
        if (length <= 2)
            return;
        int width = board[0].length;
        if (width <= 2)
            return;
        for (int i = 0; i < width; i++) {
            if(board[0][i] == 'O')
                DFS(board, 0, i);
            if(board[board.length - 1][i] == 'O')
                DFS(board, board.length - 1, i);
        }
        for(int i = 1; i < length; i++) {
            if(board[i][0] == 'O')
                DFS(board, i, 0);
            if(board[i][width - 1] == 'O')
                DFS(board, i, width - 1);
        }
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < width; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < width; j++) {
                if(board[i][j] == 'K')
                    board[i][j] = 'O';
            }
        }
    }

    public void DFS(char[][] board, int X, int Y) {
        Stack<Pair> stack = new Stack<Pair>();
        stack.push(new Pair(X, Y));
        while(!stack.isEmpty()) {
            Pair pair = stack.pop();
            if(board[pair.X][pair.Y] == 'K')
                continue;
            if(pair.X - 1 >= 0 && board[pair.X - 1][pair.Y] == 'O')
                stack.push(new Pair(pair.X - 1, pair.Y));
            if(pair.X + 1 < board.length && board[pair.X + 1][pair.Y] == 'O')
                stack.push(new Pair(pair.X + 1, pair.Y));
            if(pair.Y - 1 >= 0 && board[pair.X][pair.Y - 1] == 'O')
                stack.push(new Pair(pair.X, pair.Y - 1));
            if (pair.Y + 1 < board[0].length && board[pair.X][pair.Y + 1] == 'O')
                stack.push(new Pair(pair.X, pair.Y + 1));
            board[pair.X][pair.Y] = 'K';
        }
    }
}