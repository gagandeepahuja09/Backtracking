int factorial(int n) {
    if(n > 12)
        return INT_MAX;
    int f = 1;
    for(int i=2; i<=n; i++)
        f *= i;
    return f;    
}

void getPermutationHelper(vector<int>& num, int k, string& s) {
    if(num.size() == 0)
        return;
    int f = factorial(num.size() - 1);
    int inc = k / f;
    s += to_string(num[inc]);
    num.erase(num.begin() + inc);
    getPermutationHelper(num, k%f, s);
}

string Solution::getPermutation(int n, int k) {
    k--;
    if(k >= factorial(n))
        return "";
    vector<int> num(n);
    for(int i = 0; i < n; i++)
        num[i] = i+1;
    string s;
    getPermutationHelper(num, k, s);
    return s;
}

