class Solution {
public:
    int f(vector<double>& A) {
        if(!A.size())
            return false;
        if(A.size() == 1)
            return abs(A[0] - 24) < 1e-6;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A.size(); j++) {
                if(i != j) {
                    vector<double> B;
                    for(int k = 0; k < A.size(); k++) {
                        if(k != i && k != j)
                            B.push_back(A[k]);
                    }
                    for(int k = 0; k < 4; k++) {
                        if(k == 0)
                            B.push_back(A[i] + A[j]);
                        if(k == 1)
                            B.push_back(A[i] - A[j]);
                        if(k == 2)
                            B.push_back(A[i] * A[j]);
                        if(k == 3 && A[j])
                            B.push_back(A[i] / A[j]);
                        if(f(B))
                            return true;
                        B.pop_back();
                    }
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> A;
        for(int i : nums) A.push_back(i);
        return f(A);
    }
};
