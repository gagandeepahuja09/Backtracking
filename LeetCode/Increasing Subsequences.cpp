class Solution {
public:
    vector<vector<int>> ret;
    void incSubs(vector<int>& A, int i, vector<int>& seq) {
        if(seq.size() > 1)
            ret.push_back(seq);
        unordered_set<int> hash;
        // Hash makes sure that I do not not push a number that I already pushed
        // Let's say it was 4 6 => then I did 4 6 7 and then when another 7 came then
        // 4 6 7 won't be generated again
        for(int j = i; j < A.size(); j++) {
            if((!seq.size() || seq.back() <= A[j]) && hash.find(A[j]) == hash.end()) {
                seq.push_back(A[j]);
                incSubs(A, j + 1, seq);
                seq.pop_back();
                hash.insert(A[j]);
            }    
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        incSubs(nums, 0, seq);
        return ret;
    }
};

/* 
class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> f(vector<int>& A, int n) {
        if(n == 0) {
            vector<vector<int>> ret;
            st.insert({ A[0] });
            ret.push_back({ A[0] });
            return ret;
        }
        vector<vector<int>> ret = f(A, n - 1);
        vector<vector<int>> temp;
        for(int i = 0; i < ret.size(); i++) {
            if(ret[i].back() <= A[n]) {
                vector<int> v = ret[i];
                v.push_back(A[n]);
                if(st.find(v) == st.end()) {
                    temp.push_back(v);
                    st.insert(v);
                }
            }
        }
        for(int i = 0; i < temp.size(); i++) {
            ret.push_back(temp[i]);
        }
        vector<int> v = { A[n] };
        if(st.find(v) == st.end()) {
            ret.push_back(v);
            st.insert(v);
        }
        return ret;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size() == 0) {
            vector<vector<int>> ret;
            return ret;
        }
        vector<vector<int>> ret = f(nums, nums.size() - 1);
        vector<vector<int>> res;
        for(int i = 0; i < ret.size(); i++) {
            if(ret[i].size() > 1)
                res.push_back(ret[i]);
        }
        return res;
    }
};
*/
