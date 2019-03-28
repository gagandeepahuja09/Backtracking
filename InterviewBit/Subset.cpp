void subsetsUtil(vector<vector<int>>& res, vector<int>& v, 
vector<int> &A, int start) {
    if(start == A.size()) {
        sort(v.begin(), v.end());
        res.push_back(v);
        return;
    }
    v.push_back(A[start]);
    subsetsUtil(res, v, A, start + 1);
    v.pop_back();
    subsetsUtil(res, v, A, start + 1);
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> v;
    sort(A.begin(), A.end());
    subsetsUtil(res, v, A, 0);
    sort(res.begin(), res.end());
    return res;
}

