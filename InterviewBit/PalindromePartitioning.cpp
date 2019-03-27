bool isPalin(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if(s[i++] != s[j--])
            return false;
    }
    return true;
}

void palinPart(string A, vector<vector<string>>& res, vector<string>& v,
int start) {
    if(start > A.length() - 1) {
        res.push_back(v);
        return;
    }
    for(int i = start; i<A.size(); i++) {
        if(isPalin(A.substr(start, i - start + 1))) {
            v.push_back(A.substr(start, i - start + 1));
            palinPart(A, res, v, i + 1);
            v.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> res;
    vector<string> v;
    palinPart(A, res, v, 0);
    return res;
}

