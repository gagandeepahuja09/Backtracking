class Solution {
public:
    int parse(string& s, int& i, unordered_map<string, int>& m) {
        int n = s.size(), res = 0;
        cout << i << endl;
        if(s[i] == '(')
            ++i;
        if(s.substr(i, 3) == "add") {
            i += 4;
            int left = parse(s, i, m);
            ++i;
            int right = parse(s, i, m);
            res = left + right;
        }
        else if(s.substr(i, 4) == "mult") {
            cout << " YES ";
            i += 5;
            int left = parse(s, i, m);
            ++i;
            int right = parse(s, i, m);
            cout << left << " " << right << endl;
            res = left * right;
        }
        else if(s.substr(i, 3) == "let") {
            i += 4;
          while (i < n && s[i] != ')') {
            string var;
            if (isalpha(s[i])) while (i < n && isalnum(s[i])) var += s[i++];
            else { res = parse(s, n, i, m); break; }
            if (s[i] == ' ') {
              ++i;
              m[var] = parse(s, i, m);
              ++i;
            } else if (s[i] == ')') res = m[var];
          }
        }
        else if(isalpha(s[i])) {    // assigned variable
            string var;
            while(i < n && isalnum(s[i]))
                var += s[i++];
            res = m[var];
            cout << res << endl;
        }
        else {  // integer to be assigned
            int sign = 1;
            if(s[i] == '-') {
                sign = -1;
                ++i;
            }
            while(i < n && isdigit(s[i])) {
                res = res * 10 + (s[i++] - '0');
            }
            res *= sign;
        }
        if(s[i] == ')')
            ++i;
        cout << "rr" << i << endl;
        return res;
    }
    
    int evaluate(string expression) {
        int i = 0;
        unordered_map<string, int> mp;
        return parse(expression, i, mp);
    }
};
