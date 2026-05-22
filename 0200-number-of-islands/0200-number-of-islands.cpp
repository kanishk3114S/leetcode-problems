class Solution {
public:

    void dfs(int i , int j , vector<vector<char>>& grid , vector<vector<bool>>&vis) {

        int n = grid.size() , m = grid[0].size();
        if (i < 0 || j<0 || i>=n || j>=m || grid[i][j] == '0' || vis[i][j]) return;
        if (grid[i][j] == '1') {
            vis[i][j] = true;
        }

        dfs(i+1 ,j , grid , vis); //down
        dfs(i , j-1 , grid , vis);//left;
        dfs(i , j+1 , grid , vis); //right
        dfs(i-1 , j , grid , vis); //upper

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int cnt = 0;
        for (int i=0; i<n; i++) {

            for (int j=0; j<m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i , j , grid , vis);
                }

            }

        }

        return cnt;

    }
};