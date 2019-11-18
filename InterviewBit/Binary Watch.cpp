class Solution {
public:
    vector<int> times = { 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
    vector<string> ret;
    void f(int n, int h, int m, int start) {
        if(n == 0) {
            ret.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            return;
        }
        for(int i = start; i < times.size(); i++) {
            if(i < 4) {
                if(h + times[i] < 12)
                    f(n - 1, h + times[i], m, i + 1);
            }
            else {
                if(m + times[i] < 60)
                    f(n - 1, h, m + times[i], i + 1);   
            }
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        f(num, 0, 0, 0);
        return ret;
    }
};
