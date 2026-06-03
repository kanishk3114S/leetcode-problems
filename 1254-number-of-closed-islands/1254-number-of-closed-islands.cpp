class Solution {
public:

    void dfs(vector<vector<int>>& board , vector<vector<bool>>& vis , int row , int col , int n , int m ) {

        if (row < 0 || col < 0 || row >=n || col>=m || vis[row][col] || board[row][col] == 1) return;

        vis[row][col] = true;

        dfs(board , vis , row+1 ,col , n , m);
        dfs(board , vis , row-1 ,col , n , m);
        dfs(board , vis , row ,col-1 , n , m);
        dfs(board , vis , row ,col+1 , n , m);

    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));

        for (int i=0; i<n; i++) {

            if (grid[i][0] == 0 && !vis[i][0]) {
                dfs(grid , vis , i , 0 , n , m);
            }
            if (grid[i][m-1] == 0 && !vis[i][m-1]) {

                dfs(grid , vis , i , m-1 , n , m);

            }

        }

        for (int i=0; i<m; i++) {

            if (grid[0][i] == 0 && !vis[0][i]) {
                dfs(grid , vis , 0 , i , n , m);
            }
            if (grid[n-1][i] == 0 && !vis[n-1][i]) {

                dfs(grid , vis , n-1 , i , n , m);

            }

        }

        int cnt = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {

                if (grid[i][j] == 0 && !vis[i][j]) {
                    cnt++;
                    dfs(grid , vis , i , j , n , m);
                }
            
            }
        }

        return cnt;

    }
};