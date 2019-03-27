bool isValid(vector<string>& board, int row, int col, int n) {
    for(int i =0; i<n; i++) {
        if(board[i][col] == 'Q')
            return false;
    }
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q')
            return false;
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q')
            return false;
    }
    return true;
}

void nQueens(vector<vector<string>>& res, vector<string>& board, 
int n, int row) {
    if(row == n) {
        res.push_back(board);
        return;
    }
    for(int col=0; col<n; col++) {
        if(isValid(board, row, col, n)) {
            board[row][col] = 'Q';
            nQueens(res, board, n, row + 1);
            // Bactracking to get to previous state if 
            // that did not return correct answer
            // and it will carry forward from that state
            board[row][col] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int N) {
    vector<string> board;
    for(int i=0; i<N; i++) {
        string s = "";
        for(int j=0; j<N; j++) {
            s += '.';
        }
        board.push_back(s);
    }
    vector<vector<string>> res;
    nQueens(res, board, N, 0);
    return res;    
}

