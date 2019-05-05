bool isPalin(string s, int start, int end) {
    while(s[start] == s[end] && start < end) {
        start++, end--;
    }
    return start >= end;
}

void palinPart(string s, vector<vector<string>>& res, vector<string>& v, int start) {
    if(start >= s.size())
        res.push_back(v);    
    for(int i = start; i < s.size(); i++) {
        if(isPalin(s, start, i)) {
            v.push_back(s.substr(start, i - start + 1));
            palinPart(s, res, v, i + 1);
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

