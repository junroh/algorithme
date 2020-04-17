// https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[r].size())   return;
        if(grid[r][c]=='0')   return;
        grid[r][c]='0';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
    
    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q;
        q.push(make_pair(r,c));
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r<0 || c<0 || r>=grid.size() || c>=grid[r].size())
                continue;
            if(grid[r][c]=='0')
                continue;
            grid[r][c]='0';
            q.push(make_pair(r+1,c));
            q.push(make_pair(r-1,c));
            q.push(make_pair(r,c+1));
            q.push(make_pair(r,c-1));
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for(int r=0;r<grid.size();r++) {
            vector<char> cols = grid[r];
            for(int c=0;c<cols.size();c++) {
                if(grid[r][c]!='0') {
                    //dfs(grid,r,c);
                    bfs(grid,r,c);
                    ret++;
                }
            }
        }
        return ret++;
    }
};
