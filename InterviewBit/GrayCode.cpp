vector<string> f(int n) {
    if(n == 0) {
        vector<string> ret;
        return ret;
    }
    if(n == 1) {
        return { "0", "1" };
    }
    vector<string> prev = f(n - 1);
    vector<string> ret;
    for(int i = 0; i < prev.size(); i++) {
        if(i % 2 == 0) {
            ret.push_back(prev[i] + '0');
            ret.push_back(prev[i] + '1');
        }
        else {
            ret.push_back(prev[i] + '1');
            ret.push_back(prev[i] + '0');
        }
    }
    return ret;
}

vector<int> Solution::grayCode(int n) {
    vector<int> ret;
    vector<string> v = f(n);
    for(int i = 0; i < v.size(); i++) {
        int val = (int)stoull(v[i], NULL, 2);
        ret.push_back(val);
    }
    return ret;
}

