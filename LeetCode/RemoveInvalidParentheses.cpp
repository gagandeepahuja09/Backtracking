class Solution {
public:
    unordered_set<string> ret;
    
    vector<string> removeInvalidParentheses(string s) {
        int remLeft = 0, remRight = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                remLeft++;
            else if(s[i] == ')') {
                if(remLeft)
                    remLeft--;
                else
                    remRight++;
            }
        }
        // cout << remLeft << " " << remRight << endl;
        helper(s, 0, remLeft, remRight, 0, "");
        return vector<string>(ret.begin(), ret.end());
    }
    
    void helper(string s, int i, int remLeft, int remRight, int pair, string path) {
        if(i == s.size()) {
            if(remLeft == 0 && remRight == 0 && pair == 0) {
                cout << path << endl;
                ret.insert(path);
            }
            return;
        }
        if(s[i] != '(' && s[i] != ')')
            helper(s, i + 1, remLeft, remRight, pair, path + s[i]);
        else if(s[i] == '(') {
            helper(s, i + 1, remLeft, remRight, pair + 1, path + s[i]);
            if(remLeft > 0) {
                helper(s, i + 1, remLeft - 1, remRight, pair, path);
            }
        }
        else {
            if(pair > 0)
                helper(s, i + 1, remLeft, remRight, pair - 1, path + s[i]);
            if(remRight > 0) {
                helper(s, i + 1, remLeft, remRight, pair, path);    
            }
        }
    }
};
