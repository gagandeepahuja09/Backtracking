class Solution {
public:
    vector<vector<int>> res;
    void permuteBacktrack(vector<int>& nums, int i) {
        if (i == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        permuteBacktrack(nums, i + 1);
        for (int j = i + 1; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permuteBacktrack(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        permuteBacktrack(nums, 0);
        return res;
    }
};

// 1 2 3 (i = 1) // 2 1 3 (i = 1) // 3 2 1 (i = 1)
// 1 2 3 (i = 2) // 1 3 2 (i = 2) // 2 1 3 (i = 2) // 2 3 1 (i = 2) // 3 2 1 (i = 2) // 3 1 2 (i = 2)
