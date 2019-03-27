void permutation(vector<int> &A, vector<vector<int>>& res, int start) {
    if(start == A.size() - 1) {
        res.push_back(A);
        return;
    }    
    for(int i = start; i < A.size(); i++) {
        swap(A[start], A[i]);
        permutation(A, res, start + 1);
        swap(A[start], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    permutation(A, res, 0);
    return res;
}
