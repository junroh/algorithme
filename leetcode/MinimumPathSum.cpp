// https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minSum=INT_MAX;
    // Timeout
    void dfs(vector<vector<int>>& grid, int r, int c, int sum) {
        if(r>=grid.size() || c>=grid[r].size())
            return;

        sum += grid[r][c];
        if(sum>minSum)
            return;

        if(r+1+c+1==grid.size()+grid[grid.size()-1].size()) {
            if(sum<minSum) minSum=sum;
            return;
        }

        dfs(grid,r+1,c, sum);
        dfs(grid,r,c+1, sum);
    }
    
    void dp(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r-1;i++)
            grid[i+1][0] += grid[i][0];
        for(int i=0;i<c-1;i++)
            grid[0][i+1] += grid[0][i];
        for(int i=1;i<r;i++) {
            for(int j=1;j<c;j++)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
        minSum = grid[r-1][c-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        //dfs(grid,0,0,0);
        dp(grid);
        return minSum;
    }
};
