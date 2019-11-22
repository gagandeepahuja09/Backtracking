class Solution {
public:
    int sum, K;
    bool f(vector<int>& A, vector<int>& vis, int i, int currSum, int k) {
        if(k == 1)
            return true;
        if(currSum == 0)
            return f(A, vis, 0, sum, k - 1);
        for(int j = i; j < A.size(); j++) {
            if(!vis[j]) {
                vis[j] = 1;
                if(f(A, vis, j + 1, currSum - A[j], k))
                    return true;
                vis[j] = 0;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> vis(nums.size(), 0);
        sum = 0;
        for(int i : nums)
            sum += i;
        if(sum % k)
            return false;
        sum /= k;
        return f(nums, vis, 0, sum, k);
    }
};
