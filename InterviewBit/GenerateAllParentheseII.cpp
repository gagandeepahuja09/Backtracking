void parenthesis(vector<string>& res, string s, int co, int cc, int n) {
    if(s.length() == n) {
        res.push_back(s);
        return;
    }
    if(co == cc) {
        parenthesis(res, s + '(', co + 1, cc, n);
    }
    else if(co == n/2) {
        parenthesis(res, s + ')', co, cc + 1, n);
    }
    else if(co > cc) {
        parenthesis(res, s + '(', co + 1, cc, n);
        parenthesis(res, s + ')', co, cc + 1, n);
    }
}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> res;
    parenthesis(res, "", 0, 0, 2 * n);
    return res;
}

