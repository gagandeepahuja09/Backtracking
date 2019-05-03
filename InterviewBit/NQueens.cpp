bool isSafe(vector<string>& board, int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q')
            return false;
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q')
            return false;
    }
    for(int i = row, j = col; i >=0 && j < board.size(); i--, j++) {
        if(board[i][j] == 'Q')
            return false;
    }
    return true;
}

void nQueens(vector<vector<string>>& res, vector<string>& board, int row) {
    int n = board.size();
    if(row == n) {
        res.push_back(board);
    }
    for(int i = 0; i < n; i++) {
        if(isSafe(board, row, i)) {
            board[row][i] = 'Q';
            nQueens(res, board, row + 1);
            board[row][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> res;
    vector<string> board(A);
    string s = "";
    for(int j = 0; j < A; j++)
        s += '.';
    for(int i = 0; i < board.size(); i++) {
        board[i] = s;
    }
    nQueens(res, board, 0);
    return res;
}

