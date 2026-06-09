class Solution {
public:

    void dfs(vector<vector<int>>&grid2 , vector<vector<int>>&grid1, vector<vector<bool>>&vis , int row , int col , int n , int m , bool&isvalid) {

        if (row < 0 || col < 0 || col > m-1 || row > n-1 || vis[row][col] || grid2[row][col] == 0) return;

        if (grid2[row][col] == 1) {
            if (grid1[row][col] != 1) {
                isvalid = false;
            }
            vis[row][col] = true;
        }

        dfs(grid2 , grid1 , vis , row - 1 , col , n , m , isvalid);
        dfs(grid2 , grid1 , vis , row , col + 1 , n , m , isvalid);
        dfs(grid2 , grid1 , vis , row , col - 1 , n , m , isvalid);
        dfs(grid2 , grid1 , vis , row +1 , col , n , m , isvalid);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n = grid2.size();
        int m = grid2[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (!vis[i][j] && grid2[i][j] == 1) {
                    bool isvalid = true;
                    dfs(grid2,grid1,vis,i , j ,n,m,isvalid);
                    if (isvalid) cnt++;
                }
            }
        }

        return cnt;


    }
};