class Solution {
public:

    void dfs(vector<vector<int>>& grid , int row , int col , vector<vector<bool>>&vis , int&cnt) {

        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || vis[row][col] || grid[row][col] == 0) return;

        if (grid[row][col] == 1) {
            cnt++;
            vis[row][col] = true;
        }

        dfs(grid,row+1,col,vis,cnt);
        dfs(grid,row,col-1,vis,cnt);
        dfs(grid,row-1,col ,vis,cnt);
        dfs(grid,row,col+1,vis,cnt);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxcnt = 0;
        int cnt = 0;
        vector<vector<bool>> vis(grid.size() , vector<bool> (grid[0].size() , false));

        for (int i=0; i<grid.size(); i++) {

            for (int j=0; j<grid[0].size(); j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {

                    dfs(grid,i,j , vis , cnt);
                    maxcnt = max(maxcnt , cnt);
                    cnt = 0;

                }


            }

        }

        return maxcnt;

    }
};