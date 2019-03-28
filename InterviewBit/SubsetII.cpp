void subsetsUtil(set<vector<int>>& memo, vector<vector<int>>& res, vector<int>& v, 
vector<int> &A, int start) {
    if(start >= A.size()) {
        if(memo.find(v) == memo.end())
            res.push_back(v);
        memo.insert(v);    
        return;
    }
    v.push_back(A[start]);
    subsetsUtil(memo, res, v, A, start + 1);
    v.pop_back();
    subsetsUtil(memo, res, v, A, start + 1);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> v;
    set<vector<int>> memo;
    memo.clear();
    sort(A.begin(), A.end());
    subsetsUtil(memo, res, v, A, 0);
    sort(res.begin(), res.end());
    return res;
}
