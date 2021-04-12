class Solution {
public:
    void lettersRec(string digits, int i, vector<string>& ret, string& curr, vector<string>& v) {
        if (i == digits.size()) {
            ret.push_back(curr);
            return;
        }
        int num = digits[i] - '0';
        for (int j = 0; j < v[num].size(); j++) {
            curr += v[num][j];
            lettersRec(digits, i + 1, ret, curr, v);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        vector<string> ret = {};
        if (!digits.size()) {
            return ret;
        }
        string curr = "";
        lettersRec(digits, 0, ret, curr, v);
        return ret;
    }
};
