class Solution {
public:
    bool fNot(string& s, int& i) {
        i += 2;
        bool ans = f(s, i);
        i++;
        return !ans;
    }
    
    bool fOr(string& s, int& i) {
        i += 2;
        bool ans = false;
        ans |= f(s, i);
        while(s[i] != ')') {
            i++;
            ans |= f(s, i);
        }
        i++;
        return ans;
    }
    
    bool fAnd(string& s, int& i) {
        i += 2;
        bool ans = true;
        ans &= f(s, i);
        while(s[i] != ')') {
            i++;
            ans &= f(s, i);
        }
        i++;
        return ans;
    }
    
    bool f(string& s, int& i) {
        if(s[i] == 'f') {
            i++;
            return false;
        }
        else if(s[i] == 't') {
            i++;
            return true;
        }
        else if(s[i] == '!') {
            return fNot(s, i);
        }
        else if(s[i] == '&') {
            return fAnd(s, i);
        }
        return fOr(s, i);
    }
    
    bool parseBoolExpr(string exp) {
        int i = 0;
        return f(exp, i);
    }
};
