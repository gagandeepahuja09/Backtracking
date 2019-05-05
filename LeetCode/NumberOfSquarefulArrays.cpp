class Solution {
public:
    
    bool perfect(int n) {
        return ((int)((int)sqrt(n) * (int)sqrt(n)) == n);
    }

    bool check(int start, int end, vector<int>& A) {
        for(int i = start + 1; i < end; i++) {
            if(A[i] == A[end])
                return false;
        }
        return true;
    }

    int numPerm(vector<int>& A, int start) {
        if(start == A.size() && A.size() > 1)
            return 1;
        int ans = 0;    
        for(int i = start; i < A.size(); i++) {
            if((i == start || A[start] != A[i]) && check(start, i, A)) {
                swap(A[i], A[start]);
                if(start == 0 || perfect(A[start] + A[start - 1]))
                    ans += numPerm(A, start + 1);   
                swap(A[i], A[start]);    
            }
        }
    return ans;
    }
   
    int numSquarefulPerms(vector<int>& A) {
        return numPerm(A, 0);
    }
};
