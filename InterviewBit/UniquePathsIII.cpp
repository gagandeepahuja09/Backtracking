/*
Given a matrix of integers A of size N x M. There are 4 types of squares in it:

1. 1 represents the starting square.  There is exactly one starting square.
2. 2 represents the ending square.  There is exactly one ending square.
3. 0 represents empty squares we can walk over.
4. -1 represents obstacles that we cannot walk over.

Find and return the number of 4-directional walks from the 
starting square to the ending square, that walk over every non-obstacle square exactly 
once.
*/

int findPaths(vector<vector<int>>& A, int sx, int sy, int ex, int ey, int c0, int t0) {
    if(sx >= A.size() || sy >= A[0].size() || sx < 0 || sy < 0 || A[sx][sy] == -1)
        return 0;
    if(A[sx][sy] == 0)
        c0++; 
    if(sx == ex && sy == ey) {
        if(c0 == t0)
            return 1;
        return 0;    
    }
    int temp = A[sx][sy];
    A[sx][sy] = -1;
    vector<int> dx = { 1, 0, -1, 0};
    vector<int> dy = { 0, 1, 0,  -1};
    int ans = 0;
    for(int i = 0; i < 4; i++) {
        ans += findPaths(A, sx + dx[i], sy + dy[i], ex, ey, c0, t0);
    }
    A[sx][sy] = temp;
    if(A[sx][sy] == 0)
        c0--;
    return ans;    
} 

int Solution::solve(vector<vector<int> > &A) {
    int sx, sy, ex, ey, t0 = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[i].size(); j++) {
            if(A[i][j] == 1)
                sx = i, sy = j;
            if(A[i][j] == 0)
                t0++;
            if(A[i][j] == 2)
                ex = i, ey = j;
        }
    }
    return findPaths(A, sx, sy, ex, ey, 0, t0);
}

