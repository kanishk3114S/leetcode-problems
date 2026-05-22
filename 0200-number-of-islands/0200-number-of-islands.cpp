class Solution {
public:

    void dfs(pair<int,int> a,
             vector<vector<vector<pair<int,int>>>>& adj,
             vector<vector<bool>>& vis) {

        vis[a.first][a.second] = true;

        for (auto &p : adj[a.first][a.second]) {

            if (!vis[p.first][p.second]) {
                dfs(p, adj, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        vector<vector<vector<pair<int,int>>>> adj(
            n,
            vector<vector<pair<int,int>>>(m)
        );

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {

                    if (j > 0 && grid[i][j-1] == '1')
                        adj[i][j].push_back({i, j-1});

                    if (i > 0 && grid[i-1][j] == '1')
                        adj[i][j].push_back({i-1, j});

                    if (j < m-1 && grid[i][j+1] == '1')
                        adj[i][j].push_back({i, j+1});

                    if (i < n-1 && grid[i+1][j] == '1')
                        adj[i][j].push_back({i+1, j});
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs({i, j}, adj, vis);
                }
            }
        }

        return cnt;
    }
};