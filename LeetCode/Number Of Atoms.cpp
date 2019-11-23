class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        map<string, int> cnt = parseElement(formula, i);
        string res;
        for (auto const &p : cnt) 
            res += p.first + (p.second > 1 ? to_string(p.second) : "");
        
        return res;
    }
    
    map<string, int> parseElement(string &formula, int &i) {
        map<string, int> cnt;
        while (i < formula.size() && formula[i] != ')') {
            if (formula[i] == '(') {
                auto m = parseElement(formula, ++i);
                for (auto const &p : m) cnt[p.first] += p.second;
            }
            else {
                string atom;
                atom += formula[i++];
                while (i < formula.size() && isalpha(formula[i]) && islower(formula[i]))
                    atom += formula[i++];
                cnt[atom] += parseInt(formula, i);
            }
        }
        if (i < formula.size() && formula[i] == ')') {
            int n = parseInt(formula, ++i);
            for (auto &p : cnt) p.second *= n;
        }
        return cnt;
    }
    
    int parseInt(string& s, int &i) {
        int n = 0;
        while (i < s.length() && isdigit(s[i]))
            n = 10 * n + s[i++] - '0';
        return n == 0 ? 1 : n;
    }
};
