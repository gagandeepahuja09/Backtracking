class Solution {
public:
    int target;
    bool squarePossible(vector<int>& A, vector<int>& sides, int i) {
        if(i == A.size()) {
            bool temp = (target == sides[0] && sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]);
            return temp;
        }
        bool ans = false;
        for(int j = 0; j < 4; j++) {
            if(sides[j] + A[i] > target)
                continue;
            bool flag = false;
            for(int k = j - 1; k >= 0; k--) {
                if(sides[k] == sides[j]) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            sides[j] += A[i];
            ans |= squarePossible(A, sides, i + 1);
            sides[j] -= A[i];
        }
        return ans;
    } 
    
    bool makesquare(vector<int>& A) {
        if(A.size() < 4)
            return false;
        target = accumulate(A.begin(), A.end(), 0);
        if(target % 4)
            return false;
        target /= 4;
        cout << target << endl;
        sort(A.begin(), A.end(), greater<int>());
        vector<int> sides(4, 0);
        return squarePossible(A, sides, 0);
    }
};
