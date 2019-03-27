bool isValid(vector<vector<char>>& A, char val, int row, int col) {
    for(int i = 0; i<9; i++)
        if(A[row][i] == val)
            return false;
    for(int i = 0; i<9; i++)
        if(A[i][col] == val)
            return false;   
    int x = row - row%3;
    int y = col - col%3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(A[i + x][j + y] == val)
                return false;
        }
    }
    return true;
}

bool solveSud(vector<vector<char>>& A, int row, int col) {
    if(row == 9)
        return true;
    if(A[row][col] != '.') {
        if(col == 8) 
            return solveSud(A, row + 1, 0);
        else 
            return solveSud(A, row, col + 1);
    }    
    else {    
        for(char i = '1'; i <= '9'; i++) {
            if(isValid(A, i, row, col)) {
                A[row][col] = i;
                if(col == 8) {
                    if(solveSud(A, row + 1, 0))
                        return true;
                }
                else {
                    if(solveSud(A, row, col + 1))
                        return true;
                }
            }
        }
	// Most imp. step
        A[row][col] = '.';
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    solveSud(A, 0, 0);
}

