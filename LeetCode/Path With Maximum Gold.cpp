class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        ans = max(ans, temp + dfs(i + 1, j, grid));
        ans = max(ans, temp + dfs(i, j + 1, grid));
        ans = max(ans, temp + dfs(i - 1, j, grid));
        ans = max(ans, temp + dfs(i, j - 1, grid));
        grid[i][j] = temp;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};
