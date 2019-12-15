class CombinationIterator {
public:
    vector<string> ret;
    int cnt;
    void f(string s, string chr, int i, int l) {
        if(l < 0) {
            return;
        }
        if(i == chr.size()) {
            if(l == 0)
                ret.push_back(s);
            return;
        }
        f(s + chr[i], chr, i + 1, l - 1);
        f(s, chr, i + 1, l);
    }
    
    CombinationIterator(string chr, int l) {
        cnt = 0;
        ret.clear();
        f("", chr, 0, l);
    }
    
    string next() {
        return ret[cnt++];
    }
    
    bool hasNext() {
        return (cnt < ret.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

