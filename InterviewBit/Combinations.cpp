void combinations(vector<vector<int>>& res, vector<int>& v, 
int n, int k, int start) {
    if(k == 0) {
        res.push_back(v);
        return;
    }
    if(start == n + 1) {
        return;
    }
    v.push_back(start);
    combinations(res, v, n, k-1, start + 1);
    v.pop_back();
    combinations(res, v, n, k, start + 1);
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> v;
    combinations(res, v, n, k, 1);
    return res;
}

