vector<string> grayC(int n) {
    if(n == 1) {
        return { "0", "1" };
    }
    vector<string> ans = grayC(n - 1);
    vector<string> res;
    for(int i = 0; i < ans.size(); i++) {
        if(i % 2) {
            res.push_back(ans[i] + '1');
            res.push_back(ans[i] + '0');
        }
        else {
            res.push_back(ans[i] + '0');
            res.push_back(ans[i] + '1');
        }
    }
    return res;
}

vector<int> Solution::grayCode(int A) {
    vector<int> ret;
    if(!A)
        return ret;
    vector<string> res = grayC(A);
    for(int i = 0; i < res.size(); i++) {
        unsigned long long num = stoull(res[i], 0, 2);
        ret.push_back((int)num);
    }
    return ret;
}

