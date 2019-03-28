void combinationSumUtil(vector<vector<int>>& res, vector<int>& v, 
vector<int>& A, int B, int start) {
    if(B <= 0) {
        if(B == 0) {
            sort(v.begin(), v.end());
            res.push_back(v);
        }
        return;
    }
    if(start == A.size())
        return;
    v.push_back(A[start]);
    combinationSumUtil(res, v, A, B - A[start], start);
    v.pop_back();
    combinationSumUtil(res, v, A, B, start + 1);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int> v;
    sort(A.begin(), A.end());
    vector<int> a;
    a.push_back(A[0]);
    for(int i=1; i < A.size(); i++) {
        if(A[i] != A[i-1])
            a.push_back(A[i]);
    }
    combinationSumUtil(res, v, a, B, 0);
    sort(res.begin(), res.end());
    return res;
}

