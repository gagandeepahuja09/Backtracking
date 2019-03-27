void letterPhone(map<char, string>& mp, vector<string>& res, string A, int start, string output) {
    if(start == A.length()) {
        res.push_back(output);
        return;
    }
    char num = A[start];
    string str = mp[num];
    for(int i=0; i<str.size(); i++) {
        letterPhone(mp, res, A, start + 1, output + str[i]);
    }
}

vector<string> Solution::letterCombinations(string A) {
    map<char, string> mp;
    mp['0'] = "0";
    mp['1'] = "1";
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    vector<string> res;
    letterPhone(mp, res, A, 0, "");
    return res;
}

