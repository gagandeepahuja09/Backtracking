class Solution {
public:
    int t;
    vector<string> ret;
    void f(string num, int i, long prev, long mult, string s) {
        if(i == num.size()) {
            if(prev == t) {
                ret.push_back(s);   
            }
            return;
        }
        for(int j = i; j < num.size(); j++) {
            string temp = num.substr(i, j - i + 1);
            if(temp.size() > 1 && temp[0] == '0')
                break;
            long num1 = stol(temp);
            f(num, j + 1, prev - mult + mult * num1, mult * num1, s + "*" + temp);
            f(num, j + 1, prev + num1, num1, s + "+" + temp);
            f(num, j + 1, prev - num1, -num1, s + "-" + temp);
        }
    }
    vector<string> addOperators(string num, int target) {
        t = target;
        for(int i = 0; i < num.size(); i++) {
            string temp = num.substr(0, i + 1);
            if(temp.size() > 1 && temp[0] == '0')
                break;
            long num1 = stol(temp);
            f(num, i + 1, num1, num1, temp);
        }
        return ret;
    }
};
